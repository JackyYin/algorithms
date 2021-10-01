int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    int sum = 0, curStart = timeSeries[0];

    for (int i = 1; i< timeSeriesSize; i++) {
        if (timeSeries[i - 1] + duration - 1 < timeSeries[i]) {
            sum += timeSeries[i - 1] + duration - curStart;
            curStart = timeSeries[i];
        }
    }
    sum += timeSeries[timeSeriesSize - 1] + duration - curStart;
    return sum;
}
