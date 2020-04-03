/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod h(256);

    Song c1("Childish Gambino", "Redbone", 27);
    int result = h.addSong(c1);
    cout << "result = " << result << endl;

    h.showSongList();
    h.sortSongList();
    h.shuffle();
    cout<< endl;
    h.showSongList();
    cout << "Remaining Memory- " << h.getRemainingMemory() << endl;
    result = h.removeSong(c1);
    cout <<  "delete result = " << result << endl;
    cout << "Remaining Memory- " << h.getRemainingMemory() << endl;
    h.addSong(c1);
    h.clearMemory();
    h.showSongList();

    h.addSong(c1);

    Song c2("Frank Ocean", "Lost", 54);
    result = h.addSong(c2);
    cout << "result = " << result << endl;

    Song c3("Frank Ocean", "Lost", 22);
    result = h.addSong(c3);
    cout << "result = " << result << endl;

    Song c5("Beatles", "Hey Jude", 214);
    result = h.addSong(c5);
    cout << "add result = " << result << endl;

    Song c4("Childish Gambino", "Summertime Magic", 7);
    result = h.addSong(c4);
    cout << "result = " << result << endl;
    Song a1("Phoenix", "1901", 2);
    Song a2("Miguel", "Banana Clip", 12);
    Song a3("Calvin Harris, Frank Ocean, Migos", "Slide", 44);
    Song a4("Post Malone", "Circles", 3);
    Song a5("Mac Miller", "Self Care", 22);
    h.addSong(a1);
    h.addSong(a2);
    h.addSong(a3);
    h.addSong(a4);
    h.addSong(a5);
    h.showSongList();
    cout << endl;
    h.sortSongList();
    h.showSongList();
    h.shuffle();
    cout << endl;
    h.showSongList();

    result = h.removeSong(c3);
    cout << "delete result = " << result << endl;

    result = h.removeSong(c1);
    cout << "delete result = " << result << endl;

    h.showSongList();

    result = h.removeSong(c1);
    cout << "delete result = " << result << endl;

    result = h.removeSong(c5);
    cout << "delete result = " << result << endl;

    result = h.removeSong(c4);
    cout << "delete result = " << result << endl;


    h.showSongList();

    result = h.addSong(c5);
    cout << "add result = " << result << endl;

    h.showSongList();
    cout << "memory = " << h.getRemainingMemory() << endl;
    h.clearMemory();
    cout << "memory = " << h.getRemainingMemory() << endl;

    UtPod y(900);
    cout << "UtPod y memory=" << y.getRemainingMemory() << endl;

    UtPod x(-22);
    cout << "UtPod x memory=" << x.getRemainingMemory() << endl;
    
    cout << "\n---More Tests Below---\n" << endl;
    
    UtPod t;
    
    Song s1("Beatles", "Hey Jude1", 4);
    result = t.addSong(s1);
    cout << "result = " << result << endl;
    
    t.showSongList();
          
    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();
       
    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
       
    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
       
    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
  
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    cout << "\nStart of new Tests:\n" << endl;

    //test for memory clear. expect 512
    t.clearMemory();
    cout << "memory = " << t.getRemainingMemory() << endl;
    t.showSongList();
    cout << "\n" << endl;
    //end of test

    t.showSongList();

    //Test removing song when list is empty. expect -2
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;
    cout << "\n" << endl;
    // end of test

    t.showSongList();

    //Testing adding a max size song to an empty pod. expect 0
    Song s6("Justin Bieber", "Baby", 512);
    result = t.addSong(s6);
    cout << "add result = " << result << endl;
    t.showSongList();
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "\n" << endl;
    //end of test

    //Test adding a song to a full utpod. expect -1
    result = t.addSong(s3);
    cout << "add result = " << result << endl;
    t.showSongList();
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "\n" << endl;
    //end of test

    //Sort Test, songs added in reverse order, will sort correctly.
    t.clearMemory();

    t.addSong(s1);
    t.addSong(s2);
    t.addSong(s3);
    t.addSong(s4);
    t.addSong(s5);
    t.addSong(s6); //Baby should not add due to its size being to large
    Song s7("Space Song", "Beach House", 8);
    t.addSong(s7);


    t.showSongList();
    cout << "---Sorted Below---" << endl;

    t.sortSongList();
    t.showSongList();
    cout << "\n" << endl;
    //end of test

    //Tests if the program will remove only one copy of a song if a duplicate is added
    t.addSong(s3);
    t.sortSongList();
    t.showSongList();
    cout << "---Check for removed duplicate below---" << endl;
    t.removeSong(s3);
    t.showSongList();
    t.clearMemory();
    cout << "\n" << endl;
    //end of test

    //Tests getTotalMemory, expect 512
    cout << "Total Memory = " << t.getTotalMemory() << endl;
    cout << "\n" << endl;
    //end of test

    //Tests shuffle function
    Song s8("Rex Orange County", "Loving is Easy", 1);
    t.addSong(s8);
    Song s9("Childish Gambino", "Sober", 6);
    t.addSong(s9);
    Song s10("Frank Ocean", "Ivy", 3);
    t.addSong(s10);
    Song s11("Omar Apollo  ", "Erase", 8);
    t.addSong(s11);
    Song s12("Kevin Abstract", "Empty", 1);
    t.addSong(s12);
    Song s13("Steve Lacy", "C U Girl", 4);
    t.addSong(s13);

    t.showSongList();
    cout << "---Check Shuffled Below---" << endl;
    t.shuffle();
    t.showSongList();
    cout << "---Check Sorted Below---" << endl;
    t.sortSongList();
    t.showSongList();
}
