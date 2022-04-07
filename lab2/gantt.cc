/* being preprocessor directives */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "gantt.h"
#define OFFSET 50
#define TABLE_OVERHEAD 6
/* end preprocessor directives */

/* begin namespaces */
using namespace std;
/* end namespaces */

/* begin Task() */
Task::Task() {
  int taskNum=0;
  string taskLeader="";
  int beginOnDay=0;
  int taskDuration=0;
  string taskDescription="";
}
/* end Task() */

/* begin Task::memberFunctions() */
int Task::getTaskNum() { return taskNum; }
void Task::setTaskNum(int replace) { taskNum=replace; }
string Task::getTaskLeader() { return taskLeader; }
void Task::setTaskLeader(string replace) { taskLeader=replace; }
int Task::getBeginOnDay() { return beginOnDay; }
void Task::setBeginOnDay(int replace) { beginOnDay=replace; }
int Task::getTaskDuration() { return taskDuration; }
void Task::setTaskDuration(int replace) { taskDuration=replace; }
string Task::getTaskDescription() { return taskDescription; }
void Task::setTaskDescription(string replace) { taskDescription=replace; }
/* end Task::memberFunctions() */

/* begin Gantt() */
Gantt::Gantt() {
  vector <Task> taskList;
  string projectName="";
  string beginDate="";
  int durationInWeeks=0;
  int numberOfTeamMembers=0;
  vector <string> teamMembers;
  int numTasks=0;
  string outFileName="";
}
/* end Gantt() */

/* begin Gantt::readInData(string)
 * uses input file name in string argument to extract text data to fill gantt chart */
void Gantt::readInData(string inputFileName) {
    ifstream inFileObject(inputFileName.c_str(), ios::in);
    string trash;
    inFileObject >> trash >> projectName;
    inFileObject >> trash >> beginDate;
    inFileObject >> trash >> durationInWeeks;
    inFileObject >> trash >> numberOfTeamMembers;
    teamMembers.resize(numberOfTeamMembers);
    for(int j=0;j<numberOfTeamMembers;j++) {
      inFileObject >> trash >> teamMembers[j];
    }
    inFileObject >> trash >> numTasks;
    taskList.resize(numTasks);
    for (int i = 0; i < numTasks; i++) {
      string temp_str;
      int temp_int;
      inFileObject >> trash >> temp_int;
      taskList[i].setTaskNum(temp_int);
      inFileObject >> trash >> temp_str;
      taskList[i].setTaskLeader(temp_str);
      inFileObject >> trash >> temp_int;
      taskList[i].setBeginOnDay(temp_int);
      inFileObject >> trash >> temp_int;
      taskList[i].setTaskDuration(temp_int);
      inFileObject >> trash;
      getline(inFileObject, temp_str);
      taskList[i].setTaskDescription(temp_str);
    }
    inFileObject.close();
}
/* end Gantt::readInData(string) */

/* begin Gantt::createHTMLFile(string)
 * uses private functions of gantt class to generate an output html file given previous input data */
void Gantt::createHTMLFile(string outputFileName) {
    outFileName = outputFileName;
    startHTMLfile();
    insertHead();
    beginBody();
    ganttChartHeaderInfo();
    chartColumnLabels();
    ganttChartBody();
    taskCharts();
    endBody();
    endHTMLfile();
}
/* end Gantt::createHTMLFile(string) */

/* begin Gantt::startHTMLfile()
 * loads beginning of html commands into output file */
void Gantt::startHTMLfile() {
    ofstream outputFileObject(outFileName.c_str(), ios::out);
    outputFileObject << "<html>" << endl;
    outputFileObject.close();
}
/* end Gantt::startHTMLfile */

/* begin Gantt::insertHead()
 * loads head.html into the output file */
void Gantt::insertHead() {
    ofstream outputFileObject(outFileName.c_str(), ios::app);
    ifstream inputHead("head.html",ios::in);
    string header_stuff;
    while(getline(inputHead,header_stuff)) {
      outputFileObject<<header_stuff<<endl;
    }
    outputFileObject.close();
}
/* end Gantt::insertHead() */

/* begin Gantt::beginBody() 
 * loads beginning of html body into output file */
void Gantt::beginBody() {
    ofstream outputFileObject(outFileName.c_str(), ios::app);
    outputFileObject << "<body>" << endl;
    outputFileObject.close();
}
/* end Gantt::beginBody() */

/* begin Gantt:ganttChartHeaderInfo()
 * creates the gantt chart header and loads into output file */
void Gantt::ganttChartHeaderInfo() {
    ofstream outputFileObject(outFileName.c_str(), ios::app);
    int tableWidth = 210* durationInWeeks + OFFSET;
    outputFileObject << "<table style=\"width: " << tableWidth << "px\">" << endl;
    outputFileObject << "<tr> \n\t <td colspan=\"2\"> Project Name: "<< projectName << "</td>\n</tr>" << endl;
    outputFileObject << "<tr> \n\t <td colspan=\"2\"> Begin Date: "<< beginDate << "</td>\n</tr>" << endl;
    string duration_desc;
    if(durationInWeeks==1) duration_desc="week";
    else duration_desc="weeks";
    outputFileObject << "<tr> \n\t <td colspan=\"2\"> Project Duration: "<< durationInWeeks << " " << duration_desc << " </td>\n</tr>" << endl;
    outputFileObject << "<tr> \n\t <td colspan=\"2\"> Team Members: ";
    for(int j=0;j<numberOfTeamMembers;j++) {
      if(j!=(numberOfTeamMembers-1)) {
        outputFileObject << teamMembers[j] << ", ";
      }
      else {
        outputFileObject << teamMembers[j] << "</td>\n</tr>";
      }
    }
    outputFileObject << "<tr>\n<td style = \"height: 30px;\"> </td>\n</tr>" << endl;
    outputFileObject.close();
}
/* end Gantt::ganttChartHeaderIndo() */

/* begin Gantt::chartColumnLabels()
 * creates the column labels for the gantt chart and loads into output file */
void Gantt::chartColumnLabels() {
    ofstream outputFileObject(outFileName.c_str(), ios::app);
    int tableWidth = 210* durationInWeeks + OFFSET;
    outputFileObject << "<td style=\"width: 50px; vertical-align: center; border: dotted 1px grey;\"> " << "<b> Task Label </b> </td> " << endl;
    outputFileObject << "<td style=\"width:" << tableWidth-OFFSET+TABLE_OVERHEAD <<"px; vertical-align: bottom; border: dotted 1px grey;\">" << endl;
    outputFileObject << "<table style=\"width: " << tableWidth-OFFSET+TABLE_OVERHEAD << "px; border: dotted 1px grey;\">" << endl;
    outputFileObject << "<tr>";
    for (int i=1; i <= durationInWeeks; i++) {
      outputFileObject << "<td colspan=\"7\" style=\"text-align: center ; "<< "width:210px; border: solid 1px black;\">"<< "Week " << i << "</td>" << endl;
    }
    outputFileObject << "</tr>";
    outputFileObject << "<tr>" <<endl;
    int num_days=durationInWeeks*7;
    for(int g=0;g<num_days;g++) {
      string weekdays[7]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
      if(g%2==0) {
        outputFileObject << "<td class=\"day\"><b>" << weekdays[g%7] << "</b></td>\n" << endl;
      }
      else {
        outputFileObject << "<td class=\"day2\"><b>" << weekdays[g%7] << "</b></td>\n" << endl;
      }
    }
    outputFileObject << "</tr>";
    outputFileObject << "</table>";
    outputFileObject << "</td>";
    outputFileObject << "</tr>";
    outputFileObject.close();
}
/* end Gantt::chartColumnLabels() */

/* begin Gantt::ganttChartBody() 
 * creates the body of the gantt chart using input information, loads into output file */
void Gantt::ganttChartBody() {
    ofstream outputFileObject(outFileName.c_str(), ios::app);
    int i = 0;
    for (i=0; i < numTasks ; i++) {
      outputFileObject << "<tr>";
      outputFileObject <<"<td style=\"border:dotted 1px grey;\"> Task " << taskList[i].getTaskNum() << "</td>" << endl;
      outputFileObject <<"<td style=\"border: dotted 1px grey;\">" << endl;
      outputFileObject << "<img src=\"dot_trans.gif\" height=\"15px;\" width=\""<< 30*(taskList[i].getBeginOnDay()-1) << "px;\">" << endl;
      if (i%2 == 0) {
        outputFileObject << "<img src=\"gold.png\" height=\"15px;\" width=\""<< 30*taskList[i].getTaskDuration() << "px;\">" << endl;
      }
      else {
        outputFileObject << "<img src=\"black.png\" height=\"15px;\" width=\""<< 30*taskList[i].getTaskDuration() << "px;\">" << endl;
      }
      outputFileObject << "</td>";
      outputFileObject << "</tr>";
   }
   outputFileObject.close();
}
/* end Gantt::ganttChartBody() */

/* begin Gantt::taskCharts()
 * creates the list of tasks following the graphic chart and loads into output file */
void Gantt::taskCharts() {
    ofstream outputFileObject(outFileName.c_str(), ios::app);
    int tableWidth = 210* durationInWeeks + OFFSET;
    outputFileObject << "</table>\n<br>\n<br>" << endl;
    outputFileObject << "<table style=\"width: " << tableWidth << "px;\">" << endl;
    outputFileObject << "<tr>\n\t <td> Task <br> Label </td>" <<endl;
    outputFileObject << "<td> Task Leader </td>" << endl;
    outputFileObject << "<td> Task Description </td>\n</tr>" << endl;
    for(int r=0;r<numTasks;r++) {
      outputFileObject << "<tr>\n<td> <b> Task " << (r+1) << " </b> </td>" << endl;
      outputFileObject << "<td> " << taskList[r].getTaskLeader() << " </td>" << endl;
      outputFileObject << "<td> " << taskList[r].getTaskDescription() << " </td>\n</tr>";
    }
    outputFileObject << "</table>" << endl;
}
/* end Gantt::taskCharts() */

/* begin Gantt::endBody()
 * loads end of html body into output file */
void Gantt::endBody() {
    ofstream outputFileObject(outFileName.c_str(), ios::app);
    outputFileObject << "</body>" << endl;
    outputFileObject.close();
}
/* end Gantt::endBody() */

/* begin Gantt::endHTMLfile() 
 * loads ends of html commands into output file */
void Gantt::endHTMLfile() {
    ofstream outputFileObject(outFileName.c_str(), ios::app);
    outputFileObject << "</html>" << endl;
    outputFileObject.close();
}
/* end Gantt::endHTMLfile() */
