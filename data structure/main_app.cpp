#include <iostream> 
#include "Music_player.hpp"

using namespace std;


int main (void)
{
    MusicPlayer* mp = new MusicPlayer();
    mp->AddMusic(new MusicPlayer::Music("music_1"));
    mp->AddMusic(new MusicPlayer::Music("music_2"));
    mp->AddMusic(new MusicPlayer::Music("music_3"));

    mp->Play();

    mp->PlayNextMusic();
    mp->PlayNextMusic();
    mp->PlayPrevMusic();
    mp->PlayPrevMusic();

    mp->Play();

    return 0;



}