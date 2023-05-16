/** 
 * @file main,c
 * @author Tiago Pereira - 98360, Vitor Silva - 
 * @brief Simple implementation of one movie ticket machine for the SETR course
 * @date 2023-5-15
 * @note configuration code is based on the code provided from teacher Paulo Pedreiras
 */

/* Includes */
#include <zephyr/kernel.h>          /* for k_msleep() */
#include <zephyr/device.h>          /* for device_is_ready() and device structure */
#include <zephyr/devicetree.h>		/* for DT_NODELABEL() */
#include <zephyr/drivers/gpio.h>    /* for GPIO api*/
#include <zephyr/sys/printk.h>      /* for printk()*/

/* Time between loop iterations  */
#define SLEEP_TIME_MS   1000 

#define ERROR -1
/* States and actions*/
#define IDLE 0
#define INSERTCOINS 1
#define RETURNCOINS 2
#define BROWSE 3
#define SELECTMOVIE 4


/* Movies information */
#define NUMMOVIES 5
unsigned char movies[NUMMOVIES] = {'A','A','A','B','B'};
unsigned char session[2*NUMMOVIES] ={'1','9','2','1','2','2','1','9','2','1'};
unsigned int ticketPrice[NUMMOVIES]  ={9,11,9,10,12};

/* Program Information*/

unsigned int credit = 0;
int movieIndex = -1;
char flag = 1;

/* Initial State */
unsigned char state = IDLE;
unsigned int eventData;

/* Set the pins buttons */
/* LED 1 and buttons 1-4 are the ones on board */
/* buttons 5-8 are connected to pins labeled A0 ... A3 (gpio0 pins 3,4,28,29) */

const uint8_t buttons_pins[] = {11,12,24,25,3,4,28,29}; /* vector with pins where buttons are connected */
	
/* Get node ID for GPIO0, which has the buttons */ 
#define GPIO0_NODE DT_NODELABEL(gpio0)

/* Get the device pointer for GPIO0 */
static const struct device * gpio0_dev = DEVICE_DT_GET(GPIO0_NODE);

/* Define a variable of type static struct gpio_callback, which will latter be used to install the callback
*  It defines e.g. which pin triggers the callback and the address of the function */
static struct gpio_callback button_cb_data;



/* Browse Movies Function
* Using the buttons we can change the movie and navigate between them
* Parâmetro de entrada será uma variavel com +1 ou -1 fazendo assim variar o movieIndex
*/
int browseMovies(int up_down){
    if(up_down != 1 && up_down != -1){
        return movieIndex;
    }
    movieIndex += up_down;
	if( movieIndex > NUMMOVIES-1) movieIndex = 0;
	if( movieIndex < 0)  movieIndex = NUMMOVIES - 1;
	printk("Movie %c, %c%cH00 session, EUR %d \n", movies[movieIndex], session[2*movieIndex], session[2*movieIndex + 1], ticketPrice[movieIndex]);
    printk("Credit available: %d EUR\n", credit);
	return movieIndex;
}
/**
*  @brief Insertion of the coins, it will increase the credit of the user. He entry will be the coin value
* @param[in] coin value to be inserted
* @return int
*/
int insertCoin(int coinValue){
    credit += coinValue;
	printk("Inserted %d EUR\n", coinValue);
	printk("Credit available: %d EUR\n", credit);
    return credit;
}
/**
*  @brief Pick your ticket, that is issued if the user has enough credit
* @param[in] movieIndex The index of the movie that the user chooses
* @return int
*/

int selectMovie(int movieIndex){
    if(movieIndex < 0 && movieIndex > 5){
        return ERROR;
    }
    if(credit < ticketPrice[movieIndex]){
        printk("Not enough credit. Ticket not issued\n");
        return INSERTCOINS;
    }
    credit -= ticketPrice[movieIndex];
	printk("Ticket for movie %c issued. Remaining credit %d EUR\n",movies[movieIndex], credit);
	printk("Please be the in the movie theater a little before %c%cH00\n",  session[2*movieIndex], session[2*movieIndex + 1]);
    return IDLE;
}
/**
*  @brief return all the credits that the user has left, leaving the credit to zero
*/

void returnCredits(){
	printk("%d EUR retorned",credit);
	credit = 0;
}

/**
 * @brief Function that chooses the current state of the program
 * @param[in] event event data, to use as the parameter of the functions of the program
 * @param[in] ActualState the actual state of the program
*/

void programLoop(int event, char ActualState){
	switch(state){
		case IDLE:
				printk("Hello, welcome to the movie ticket machine\n");
				printk("Your current credit is %d EUR\n", credit);
				state = ActualState;
				eventData = event;
				break;
		case BROWSE:
			browseMovies(event);
			state = BROWSE;
			break;
		case RETURNCOINS:
			returnCredits();
			state = ActualState;
			break;
		case INSERTCOINS:
			state = insertCoin(event);
			break;
		case SELECTMOVIE: 
			state = selectMovie(event);
			break;
			
		default:
			state = IDLE;
	}
}


/* variable that contains the number of the pressed button*/
int button = 0;

/* Define a callback function. It is like an ISR (and runs in the cotext of an ISR) */
/* that is called when the button is pressed and updates the variable button to the*/

/**
 * @brief Defines a callback function that is called when the buttons are pressed and updates the varable button to the value of the button pressed
*/
void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
	int i=0;



	/* Identify the button(s) that was(ere) hit*/
	for(i=0; i<sizeof(buttons_pins); i++){		
		if(BIT(buttons_pins[i]) & pins) {
			button = i+1;
		}
	} 
}

/* 
 * The main function
 */
void main(void)
{
	int ret, i;
	uint32_t pinmask = 0; /* Mask for setting the pins that shall generate interrupts */
	
	/* Welcome message */
	printk("Digital IO accessing IO pins not set via DT (external buttons in the case) \n\r");
	printk("Hit buttons 1-8 (1...4 internal, 5-8 external connected to A0...A3). Led toggles and button ID printed at console \n\r");

	/* Check if gpio0 device is ready */
	if (!device_is_ready(gpio0_dev)) {
		printk("Error: gpio0 device is not ready\n");
		return;
	} else {
		printk("Success: gpio0 device is ready\n");
	}


	for(i=0; i<sizeof(buttons_pins); i++) {
		ret = gpio_pin_configure(gpio0_dev, buttons_pins[i], GPIO_INPUT | GPIO_PULL_UP);
		if (ret < 0) {
			printk("Error: gpio_pin_configure failed for button %d/pin %d, error:%d\n\r", i+1,buttons_pins[i], ret);
			return;
		} else {
			printk("Success: gpio_pin_configure for button %d/pin %d\n\r", i+1,buttons_pins[i]);
		}
	}

	/* Configure the interrupt on the button's pin */
	for(i=0; i<sizeof(buttons_pins); i++) {
		ret = gpio_pin_interrupt_configure(gpio0_dev, buttons_pins[i], GPIO_INT_EDGE_TO_ACTIVE );
		if (ret < 0) {
			printk("Error: gpio_pin_interrupt_configure failed for button %d / pin %d, error:%d", i+1, buttons_pins[i], ret);
			return;
		}
	}

	k_msleep(2*SLEEP_TIME_MS);
	/* HW init done!*/
	printk("All devices initialized sucesfully!\n\r");

	/* Initialize the static struct gpio_callback variable   */
	pinmask=0;
	for(i=0; i<sizeof(buttons_pins); i++) {
		pinmask |= BIT(buttons_pins[i]);
	}
    gpio_init_callback(&button_cb_data, button_pressed, pinmask); 	
	
	/* Add the callback function by calling gpio_add_callback()   */
	gpio_add_callback(gpio0_dev, &button_cb_data);
	button = 10; // Just a random number impossible to onbtain from the buttons to enter in the right condition of the code 
	/* 
 	 * The main loop
 	 */ 

	printk("\n\n\n");
	while (1) {
		/* Just sleep. Led on/off is done by the int callback */
		//char nextState;
		switch(button){
			case 1:
				eventData = 1;
				state = BROWSE;
				break;
			case 2:
				if(state == BROWSE){
					eventData = movieIndex;
					state = SELECTMOVIE;
					break;
				}else{
					button = 0;
					printk("Select you movie first, click on de up/down button");
				}
				break;
			case 3:
				eventData = -1;
				state = BROWSE;
				break;
			case 4:
				eventData = credit;
				state = RETURNCOINS;
				break;
			case 5:
				eventData = 1;
				state = INSERTCOINS;
				break;
			case 6:
				eventData = 2;
				state = INSERTCOINS;
				break;
			case 7:
				eventData = 5;
				state = INSERTCOINS;
				break;
			case 8:
				eventData = 10;
				state = INSERTCOINS;
				break;
			default: 
				break;
			
		}

		// Just to guarantee that the button only changes one time the program
		if(button != 0){
			programLoop(eventData, state);
		}
		button = 0;
		k_msleep(SLEEP_TIME_MS);
	}
}
