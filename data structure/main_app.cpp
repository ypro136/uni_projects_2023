#include <iostream> 
#include "Music_player.hpp"
#include "gui.hpp"
#include "raylib/src/raylib.h"
#include <bits/stdc++.h> 

using namespace std;

Color play_color = RED;
bool togle = true;
string temp_string = " ";
bool m = false;
int num = 0;

Color rgb_1 = {9 ,38 ,53, 255};
Color rgb_2 = {27, 66, 66, 255};
Color rgb_3 = {92, 131, 116, 255};
Color rgb_4 = {158, 200, 185, 255};



    MusicPlayer* music_player = new MusicPlayer();
    


void _play_button()
{
    if (togle == true) 
    {
        play_color = GREEN; 
        togle = false;
        temp_string = " is Playing Right Now...";
    }
    else if (togle == false) 
    {
        play_color = RED; 
        togle = true;
        temp_string = " is paused Right Now...";
    }

    music_player->Play();
}
void _next_button()
{
    music_player->PlayNextMusic();
}
void _prev_button()
{
    music_player->PlayPrevMusic();
}
void _add_button()
{
    music_player->AddMusic(new MusicPlayer::Music("music " + to_string(num++)));
    m = true;
}


int main (void)
{
    gui GUI;

    Vector2 pos , size;

    button *play_button = GUI.create_button(pos = {250, 350}, size = {100,50}, "play" , _play_button);
    button *next_button = GUI.create_button(pos = {400, 350}, size = {100,50}, "next" , _next_button);
    button *prev_button = GUI.create_button(pos = {100, 350}, size = {100,50}, "prev" , _prev_button);
    button *add_button = GUI.create_button(pos = {650, 350}, size = {100,50}, "add" , _add_button);



    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        GUI.run_events();

        GUI.do_actions();


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(rgb_1);

        GUI.draw_button(play_button ,temp_string.c_str() ,play_color);
        GUI.draw_button(next_button ,temp_string.c_str() ,rgb_3);
        GUI.draw_button(prev_button ,temp_string.c_str() ,rgb_3);
        GUI.draw_button(add_button ,temp_string.c_str() ,rgb_4);

        DrawText(temp_string.c_str(), 280, 100, 20, LIGHTGRAY);
        if(m)
        {
            DrawText(music_player->currentSong->songName.c_str(), 320, 75, 20, LIGHTGRAY);
        }


        EndDrawing();
        //----------------------------------------------------------------------------------
    }


   
    GUI.destroy();

    return 0;



}