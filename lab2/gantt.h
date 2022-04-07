/* begin preprocessor directives */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
/* end preprocessor directives */

/* begin namespaces */
using namespace std;
/* end namespaces */

/* begin Task interface */
class Task {
    public:
      Task();
      int getTaskNum();
      void setTaskNum(int);
      string getTaskLeader();
      void setTaskLeader(string);
      int getBeginOnDay();
      void setBeginOnDay(int);
      int getTaskDuration();
      void setTaskDuration(int);
      string getTaskDescription();
      void setTaskDescription(string);

    private:
      int taskNum;
      string taskLeader;
      int beginOnDay;
      int taskDuration;
      string taskDescription;
};
/* end Task interface */

/* begin Gantt interface */
class Gantt {
   public:
      Gantt();
      void readInData(string);
      void createHTMLFile(string);

   private:
      void startHTMLfile();
      void endHTMLfile();
      void insertHead();
      void beginBody();
      void endBody();
      void ganttChartHeaderInfo();
      void chartColumnLabels();
      void ganttChartBody();
      void taskCharts();

   private:
       vector <Task> taskList;
       string projectName;
       string beginDate;
       int durationInWeeks;
       int numberOfTeamMembers;
       vector <string> teamMembers;
       int numTasks;
       string outFileName;
};
/* end Gantt interface */
