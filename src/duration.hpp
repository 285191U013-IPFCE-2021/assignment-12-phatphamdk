#ifndef DURATION_HPP
#define DURATION_HPP


class Duration{ 
    private:
    int time; // 1a
    int alarm;
    bool alarmHasBeenSet;
    

    public:
    Duration();
    ~Duration();
    int getDuration();
    Duration(int t);
    bool tick();
    void setAlarm();
    void setAlarm(int t);
    bool tick(int dt);
    bool checkAndUpdateAlarm();
    bool hasAlarmBeenSet();
    
};

#endif
