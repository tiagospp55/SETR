dtInit(){
    int temperature[24];
    extern count;
    return temperature;
}

int dtStat(int vector, int * max, int * min, int * avg){
    int i;
    int sum = 0;
    for(i = 0; i < 24; i++){
        if(vector[i] > max){
            *max = vector[i];
        }
        if(vector[i] < min){
            *min = vector[i];
        }
        sum += vector[i];
    }

    int avg = sum / 24;

    return 0;
}