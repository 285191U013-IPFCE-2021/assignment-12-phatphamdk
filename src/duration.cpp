#include <stddef.h>
#include "../src/duration.hpp"
#include <assert.h>
#include <stdbool.h>


Duration::Duration(){
 time = 0;
 alarm = -1;
 alarmHasBeenSet = false;
};

int Duration::getDuration(){ //1a
     return time;
}
Duration::Duration(int t){
 if(t>0){
 time = t;
 alarm =-1;
 alarmHasBeenSet = false;
 }
};

Duration::~Duration(){}

bool Duration::tick(){
     time++;
     return checkAndUpdateAlarm();
};

bool Duration::tick(int dt){
     assert(dt>=0);
     time = time + dt;
     return checkAndUpdateAlarm();
     
};

void Duration:: setAlarm(int t){
     if(t>time){
     alarm = t;
     alarmHasBeenSet=true;
     }
     return;
};

void Duration::setAlarm(){
     alarm = -1;
     alarmHasBeenSet=false;
};


bool Duration::checkAndUpdateAlarm(){
     if(time>=alarm){
          setAlarm();
          return true;
     }
     else 
          return false;
};

bool Duration::hasAlarmBeenSet(){
  return alarmHasBeenSet;
};