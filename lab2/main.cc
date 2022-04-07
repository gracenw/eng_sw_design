/* begin preprocessor directives */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "gantt.h"
/* end preprocessor directives */

/* begin namespaces */
using namespace std;
/* end namespaces */

/* begin main() */
int main(int argc, char * * argv) {
    Gantt Lab2GanttObject;
    if (argc < 3)
      cout << "please specify an input file name and output html file name" << endl;
    else {
      ifstream inputFile(argv[1], ios::in);
      if (!inputFile) {
         cout << "The input file does not exist!!" << endl;
      }
      else {
         inputFile.close();
         Lab2GanttObject.readInData(argv[1]);
         Lab2GanttObject.createHTMLFile(argv[2]);
      }
   }
}
/* end main() */
