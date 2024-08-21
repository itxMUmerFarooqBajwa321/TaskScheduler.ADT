#include "SchedulerApp.h"
void SchedulerApp::startApp()
{
    Task t1 { Date{21,8,2024},Time{12,0,0},String{"Pate pooja"} };
    Task t2{ Date{21,8,2024},Time{12,30,0},String{"run"} };
    Task t3{ Date {21,8,2024} , Time {1,0,0}, String {"Samosa Khana h"} };
    Scheduler s1{};
    s1.addTask(t1);
    s1.addTask(t2);
    s1.addTask(t3);
    Scheduler s2;
    s2= s1;
    s2.displayTodaysTasks();
}
