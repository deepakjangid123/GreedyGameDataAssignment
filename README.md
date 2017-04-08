# GreedyGameDataAssignment
Description about approach is explained here

First of all, to read and store the data I have taken a hashmap with two string fields.
After storing(make_pair) them in hashmap I have calculated the time difference between each start and stop time of session and also  between start time of current session and end time of last session.
If those time differences are meeting the defined criteria(as in question) I have made them a valid session and counted number of such sessions.
To convert string in time I have used sscanf(string,"%H:%M:%S",&h,&m,&s).
