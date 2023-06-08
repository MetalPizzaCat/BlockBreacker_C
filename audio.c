#include "audio.h"

Mix_Chunk *load_from_file(const char *path)
{
    Mix_Chunk *snd = Mix_LoadWAV(path);
    if (snd == NULL)
    {
        fprintf(stderr, "Failed to load %s sound effect! SDL_mixer Error: %s\n", path, Mix_GetError());
        return NULL;
    }
    return snd;
}

int32_t init_audio(AudioManager *audio)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        fprintf(stderr, "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return 0;
    }
    audio->destruction_sound = load_from_file(GAME_DESTRUCTION_SOUND_PATH);
    audio->fail_sound = load_from_file(GAME_FAIL_SOUND_PATH);
    audio->hit_sound = load_from_file(GAME_HIT_SOUND_PATH);
    audio->win_sound = load_from_file(GAME_WIN_SOUND_PATH);
    return 1;
}

void play_sound_hit(AudioManager *manager)
{
    if (manager->hit_sound != NULL)
    {
        Mix_PlayChannel(-1, manager->hit_sound, 0);
    }
}
void play_sound_fail(AudioManager *manager)
{
    if (manager->fail_sound != NULL)
    {
        Mix_PlayChannel(-1, manager->fail_sound, 0);
    }
}
void play_sound_destruction(AudioManager *manager)
{
    if (manager->destruction_sound != NULL)
    {
        Mix_PlayChannel(-1, manager->destruction_sound, 0);
    }
}

void play_sound_win(AudioManager *manager)
{
    if (manager->win_sound != NULL)
    {
        Mix_PlayChannel(-1, manager->win_sound, 0);
    }
}

void free_audio(AudioManager *audio)
{
    Mix_FreeChunk(audio->destruction_sound);
    Mix_FreeChunk(audio->fail_sound);
    Mix_FreeChunk(audio->hit_sound);
    Mix_Quit();
}