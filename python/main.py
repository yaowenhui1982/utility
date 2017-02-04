#! /usr/bin/python                                                                                                                                          
import commands
import sys 

def GetStatistics():
    name2Size = {};
    count = 0;
    for line in open(sys.argv[1]):
        line = line.strip('\n');    
        if line.endswith("/"):
            continue;
        command = "ls -s " + line + "*";
        ret, output = commands.getstatusoutput(command);
        if 0 != ret:
            print "RunError", line, command, output;
            continue;
        outputLines = output.split('\n'); 
        for ol in outputLines:
            if ol.find(line) > 0:
                name2Size[ol.split(" ")[1]]= ol.split(" ")[0];
    nameList = [];
    for name in name2Size:
        print name, name2Size[name], #not output new line
        nameList.append(name);
    name2Size.clear();
    nameList = []; #empty the list
if __name__ == "__main__":
    GetStatistics();
    sys.exit(0);
