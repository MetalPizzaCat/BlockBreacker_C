#pragma once
#include <SDL_mixer.h>

/// @brief Audio system object that stores information about game sounds
typedef struct
{
    Mix_Chunk *fail_sound;
    Mix_Chunk *hit_sound;
    Mix_Chunk *destruction_sound;
    Mix_Chunk *win_sound;
} AudioManager;

/// @brief Load a sound effect from a file or print the error
/// @param path Path to the file
/// @return Sound effect pointer or null if the sound failed to load
Mix_Chunk *load_from_file(const char *path);

/// @brief Initialises audio system and loads game sounds based on path in CMake configuration
/// @param audio Audio system handle
/// @return 1 if init was successful, 0 otherwise
int32_t init_audio(AudioManager *audio);

/// @brief Disables audio system and frees memory used by the system and loaded sounds
/// @param audio Audio system handle
void free_audio(AudioManager *audio);

/// @brief Plays the hit sound(or no sound if loading failed)
/// @param manager 
void play_sound_hit(AudioManager*manager);

/// @brief Plays the fail sound(or no sound if loading failed)
/// @param manager 
void play_sound_fail(AudioManager*manager);

/// @brief Plays the win sound(or no sound if loading failed)
/// @param manager 
void play_sound_win(AudioManager*manager);


/// @brief Plays the destruction sound(or no sound if loading failed)
/// @param manager 
void play_sound_destruction(AudioManager*manager);