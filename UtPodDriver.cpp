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

    Song s1("Childish Gambino", "Redbone", 27);
    int result = h.addSong(s1);
    cout << "result = " << result << endl;

    h.showSongList();
    h.sortSongList();
    h.shuffle();
    cout<< endl;
    h.showSongList();
    cout << "Remaining Memory- " << h.getRemainingMemory() << endl;
    result = h.removeSong(s1);
    cout <<  "delete result = " << result << endl;
    cout << "Remaining Memory- " << h.getRemainingMemory() << endl;
    h.addSong(s1);
    h.clearMemory();
    h.showSongList();

    h.addSong(s1);

    Song s2("Frank Ocean", "Lost", 54);
    result = h.addSong(s2);
    cout << "result = " << result << endl;

    Song s3("Frank Ocean", "Lost", 22);
    result = h.addSong(s3);
    cout << "result = " << result << endl;

    Song s5("Beatles", "Hey Jude", 214);
    result = h.addSong(s5);
    cout << "add result = " << result << endl;

    Song s4("Childish Gambino", "Summertime Magic", 7);
    result = h.addSong(s4);
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

    result = h.removeSong(s3);
    cout << "delete result = " << result << endl;

    result = h.removeSong(s1);
    cout << "delete result = " << result << endl;

    h.showSongList();

    result = h.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = h.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = h.removeSong(s4);
    cout << "delete result = " << result << endl;


    h.showSongList();

    result = h.addSong(s5);
    cout << "add result = " << result << endl;

    h.showSongList();
    cout << "memory = " << h.getRemainingMemory() << endl;
    h.clearMemory();
    cout << "memory = " << h.getRemainingMemory() << endl;

    UtPod y(900);
    cout << "UtPod y memory=" << y.getRemainingMemory() << endl;

    UtPod x(-22);
    cout << "UtPod x memory=" << x.getRemainingMemory() << endl;

}
