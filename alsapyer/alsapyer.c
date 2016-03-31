/* alsapyer.c
 * 
 * A ridicolousy simple Python binding for libalsaplayer
 *
 * Author: Leonardo
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 * Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
 *
 * Everyone is permitted to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 *
 */

#include <Python.h>
#include <alsaplayer/control.h>

static PyObject *
alsapyer_find_session(PyObject *self, PyObject *args)
{
    char *session_name;
    int session = -1, result;

    if (!PyArg_ParseTuple(args, "s", &session_name))
        return NULL;

    result = ap_find_session(session_name, &session);

    if (result == -1)
        return NULL;

    return Py_BuildValue("i", session);
}

static PyObject *
alsapyer_session_running(PyObject *self, PyObject *args){

    int session, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_session_running(session);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_version(PyObject *self, PyObject *args){

    int result;

    result = ap_version();

    return Py_BuildValue("i", result);
}




static PyObject *
alsapyer_play(PyObject *self, PyObject *args){

    int session, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_play(session);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_stop(PyObject *self, PyObject *args){

    int session, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_stop(session);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_unpause(PyObject *self, PyObject *args){

    int session, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_unpause(session);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_pause(PyObject *self, PyObject *args){

    int session, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_pause(session);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_next(PyObject *self, PyObject *args){

    int session, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_next(session);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_prev(PyObject *self, PyObject *args){

    int session, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_prev(session);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_ping(PyObject *self, PyObject *args){

    int session, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_ping(session);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_quit(PyObject *self, PyObject *args){

    int session, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_quit(session);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_clear_playlist(PyObject *self, PyObject *args){

    int session, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_clear_playlist(session);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_add_path(PyObject *self, PyObject *args){

    char *path;
    int session, result;

    if (!PyArg_ParseTuple(args, "is", &session, &path))
        return NULL;

    result = ap_add_path(session, (const char *)path);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_add_and_play(PyObject *self, PyObject *args){

    char *path;
    int session, result;

    if (!PyArg_ParseTuple(args, "is", &session, &path))
        return NULL;

    result = ap_add_and_play(session, (const char *)path);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_add_playlist(PyObject *self, PyObject *args){

    char *playlistfile;
    int session, result;

    if (!PyArg_ParseTuple(args, "is", &session, &playlistfile))
        return NULL;

    result = ap_add_playlist(session, (const char *)playlistfile);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_shuffle_playlist(PyObject *self, PyObject *args){

    int session, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_shuffle_playlist(session);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_save_playlist(PyObject *self, PyObject *args){

    int session, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_save_playlist(session);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_get_playlist_length(PyObject *self, PyObject *args){

    int session, length, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_get_playlist_length(session, &length);

    return Py_BuildValue("i", length);
}

static PyObject *
alsapyer_set_speed(PyObject *self, PyObject *args){

    int session, result;
    float speed;

    if (!PyArg_ParseTuple(args, "if", &session, &speed))
        return NULL;

    if (speed > 4)
        speed = 4;
    else if ( speed < -4)
        speed = -4;

    result = ap_set_speed(session, speed);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_get_speed(PyObject *self, PyObject *args){

    int session, result;
    float speed;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_get_speed(session, &speed);

    return Py_BuildValue("f", speed);
}

static PyObject *
alsapyer_set_volume(PyObject *self, PyObject *args){

    int session, result;
    float volume;

    if (!PyArg_ParseTuple(args, "if", &session, &volume))
        return NULL;

    if (volume > 1)
        volume = 1;
    else if (volume < 0)
        volume = 0;

    result = ap_set_volume(session, volume);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_get_volume(PyObject *self, PyObject *args){

    int session, result;
    float volume;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_get_volume(session, &volume);

    return Py_BuildValue("f", volume);
}

static PyObject *
alsapyer_set_pan(PyObject *self, PyObject *args){

    int session, result;
    float pan; 

    if (!PyArg_ParseTuple(args, "if", &session, &pan))
        return NULL;

    if (pan > 1)
        pan = 1;
    else if (pan < -1)
        pan = -1;

    result = ap_set_pan(session, pan);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_get_pan(PyObject *self, PyObject *args){

    int session, result;
    float pan; 

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_get_pan(session, &pan);

    return Py_BuildValue("f", pan);
}


#ifdef AP_CONTROL_VERSION

static PyObject *
alsapyer_is_paused(PyObject *self, PyObject *args){

    int session, paused, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_is_paused(session, &paused);

    return Py_BuildValue("i", paused);
}

#endif




static PyObject *
alsapyer_set_looping(PyObject *self, PyObject *args){

    int session, val, result;

    if (!PyArg_ParseTuple(args, "ii", &session, &val))
        return NULL;

    result = ap_set_looping(session, val);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_is_looping(PyObject *self, PyObject *args){

    int session, val, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_is_looping(session, &val);

    return Py_BuildValue("i", val);
}

static PyObject *
alsapyer_set_playlist_looping(PyObject *self, PyObject *args){

    int session, val, result;

    if (!PyArg_ParseTuple(args, "ii", &session, &val))
        return NULL;

    result = ap_set_playlist_looping(session, val);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_is_playlist_looping(PyObject *self, PyObject *args){

    int session, val, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_is_playlist_looping(session, &val);

    return Py_BuildValue("i", val);
}





static PyObject *
alsapyer_get_tracks(PyObject *self, PyObject *args){

    int session, nr_tracks, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_get_tracks(session, &nr_tracks);

    return Py_BuildValue("i", nr_tracks);
}





static PyObject *
alsapyer_get_session_name(PyObject *self, PyObject *args){

    int session, result;
    char str[AP_SESSION_MAX];

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    bzero(&str, sizeof(char) * 256);
    result = ap_get_session_name(session, &str[0]);

    return Py_BuildValue("s", &str);
}





static PyObject *
alsapyer_get_title(PyObject *self, PyObject *args){

    int session, result;
    char str[AP_TITLE_MAX];

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    bzero(&str, sizeof(char) * 256);
    result = ap_get_title(session, &str[0]);

    return Py_BuildValue("s", &str);
}

static PyObject *
alsapyer_get_artist(PyObject *self, PyObject *args){

    int session, result;
    char str[AP_ARTIST_MAX];

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    bzero(&str, sizeof(char) * 256);
    result = ap_get_artist(session, &str[0]);

    return Py_BuildValue("s", &str);
}

static PyObject *
alsapyer_get_album(PyObject *self, PyObject *args){

    int session, result;
    char str[AP_ALBUM_MAX];

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    bzero(&str, sizeof(char) * 256);
    result = ap_get_album(session, &str[0]);

    return Py_BuildValue("s", &str);
}

static PyObject *
alsapyer_get_genre(PyObject *self, PyObject *args){

    int session, result;
    char str[AP_GENRE_MAX];

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    bzero(&str, sizeof(char) * 256);
    result = ap_get_genre(session, &str[0]);

    return Py_BuildValue("s", &str);
}

static PyObject *
alsapyer_get_year(PyObject *self, PyObject *args){

    int session, result;
    char str[AP_YEAR_MAX];

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    bzero(&str, sizeof(char) * 256);
    result = ap_get_year(session, &str[0]);

    return Py_BuildValue("s", &str);
}

static PyObject *
alsapyer_get_track_number(PyObject *self, PyObject *args){

    int session, result;
    char str[AP_YEAR_MAX];

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    bzero(&str, sizeof(char) * 256);
    result = ap_get_track_number(session, &str[0]);

    return Py_BuildValue("s", &str);
}

static PyObject *
alsapyer_get_comment(PyObject *self, PyObject *args){

    int session, result;
    char str[AP_COMMENT_MAX];

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    bzero(&str, sizeof(char) * 256);
    result = ap_get_comment(session, &str[0]);

    return Py_BuildValue("s", &str);
}

static PyObject *
alsapyer_get_file_path(PyObject *self, PyObject *args){

    int session, result;
    char str[AP_FILE_PATH_MAX];

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    bzero(&str, sizeof(char) * 256);
    result = ap_get_file_path(session, &str[0]);

    return Py_BuildValue("s", &str);
}





static PyObject *
alsapyer_set_position(PyObject *self, PyObject *args){

    int session, val, result;

    if (!PyArg_ParseTuple(args, "ii", &session, &val))
        return NULL;

    result = ap_set_position(session, val);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_get_position(PyObject *self, PyObject *args){

    int session, val, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_get_position(session, &val);

    return Py_BuildValue("i", val);
}

static PyObject *
alsapyer_set_position_relative(PyObject *self, PyObject *args){

    int session, pos, result;

    if (!PyArg_ParseTuple(args, "ii", &session, &pos))
        return NULL;

    result = ap_set_position_relative(session, pos);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_get_length(PyObject *self, PyObject *args){

    int session, val, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_get_length(session, &val);

    return Py_BuildValue("i", val);
}

#ifdef AP_CONTROL_VERSION
static PyObject *
alsapyer_set_block(PyObject *self, PyObject *args){

    int session, block, result;

    if (!PyArg_ParseTuple(args, "ii", &session, &block))
        return NULL;

    result = ap_set_block(session, block);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_get_block(PyObject *self, PyObject *args){

    int session, val, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_get_block(session, &val);

    return Py_BuildValue("i", val);
}

static PyObject *
alsapyer_get_blocks(PyObject *self, PyObject *args){

    int session, val, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_get_blocks(session, &val);

    return Py_BuildValue("i", val);
}
#endif

static PyObject *
alsapyer_get_stream_type(PyObject *self, PyObject *args){

    int session, result;
    char str[AP_STREAM_TYPE_MAX];

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    bzero(&str, sizeof(char) * 256);
    result = ap_get_stream_type(session, &str[0]);

    return Py_BuildValue("s", &str);
}

static PyObject *
alsapyer_get_status(PyObject *self, PyObject *args){

    int session, result;
    char str[AP_STATUS_MAX];

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    bzero(&str, sizeof(char) * 256);
    result = ap_get_status(session, &str[0]);

    return Py_BuildValue("s", &str);
}





static PyObject *
alsapyer_is_playing(PyObject *self, PyObject *args){

    int session, paused = 0, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_is_playing(session, &paused);

    return Py_BuildValue("i", paused);
}




static PyObject *
alsapyer_sort(PyObject *self, PyObject *args){
// Pointer to sequence of sorting fields.
// This is temporary variable, it is valid while Sort function active.
// Meaning of chars:
// a - sort by artist in descending direction,
// A - sort by astist in ascending direction,
// l - sort by album in descending direction,
// L - sort by album in ascending direction,
// t - sort by title in descending direction,
// T - sort by title in ascending direction,
// y - sort by year in descending direction,
// Y - sort by year in ascending direction,
// n - sort by track number in descending direction,
// N - sort by track number in ascending direction,
// c - sort by comment in descending direction,
// C - sort by comment in ascending direction,
// f - sort by filename in descending direction,
// F - sort by filename in ascending direction,
// g - sort by genre in descending direction,
// G - sort by genre in ascending direction,
// p - sort by playtime in descending direction,
// P - sort by playtime in ascending direction.

    int session, result;
    char *str;

    if (!PyArg_ParseTuple(args, "is", &session, &str))
        return NULL;

    bzero(&str, sizeof(char) * 256);
    result = ap_sort(session, str);

    return Py_BuildValue("s", &str);
}

static PyObject *
alsapyer_jump_to(PyObject *self, PyObject *args){

    int session, pos, result;

    if (!PyArg_ParseTuple(args, "ii", &session, &pos))
        return NULL;

    result = ap_jump_to(session, pos);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_get_playlist_position(PyObject *self, PyObject *args){

    int session, pos, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_get_playlist_position(session, &pos);

    return Py_BuildValue("i", pos);
}

static PyObject *
alsapyer_get_file_path_for_track(PyObject *self, PyObject *args){

    int session, pos, result;
    char path[AP_FILE_PATH_MAX];

    if (!PyArg_ParseTuple(args, "ii", &session, &pos))
        return NULL;

    bzero(&path, sizeof(char) * 256);
    result = ap_get_file_path_for_track(session, &path[0], pos);

    return Py_BuildValue("s", &path[0]);
}

static PyObject *
alsapyer_insert(PyObject *self, PyObject *args){

    int session, pos, result;
    char path[AP_FILE_PATH_MAX];

    if (!PyArg_ParseTuple(args, "isi", &session, &path, &pos))
        return NULL;

    result = ap_insert(session, &path[0], pos);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_remove(PyObject *self, PyObject *args){

    int session, pos, result;

    if (!PyArg_ParseTuple(args, "ii", &session, &pos))
        return NULL;

    result = ap_remove(session, pos);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_set_current(PyObject *self, PyObject *args){

    int session, pos, result;

    if (!PyArg_ParseTuple(args, "ii", &session, &pos))
        return NULL;

    result = ap_set_current(session, pos);

    return Py_BuildValue("i", result);
}

static PyObject *
alsapyer_get_playlist(PyObject *self, PyObject *args){

    int session, result, argc, i;
    char **the_list;
    PyObject *list = NULL, *ref = NULL;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_get_playlist(session, &argc, &the_list);

    list = PyList_New(argc);
    
    for(i = 0; i < argc; i++) {
        ref = PyUnicode_FromString(*(the_list + i));
        PyList_SetItem(list, (Py_ssize_t) i, ref);
    }

    return list;
}


static PyMethodDef AlsapyerMethods[] = {
    {"find_session", alsapyer_find_session, METH_VARARGS, "Find a session"},
    {"session_running", alsapyer_session_running, METH_VARARGS, "Check if a session is running"},
    {"version", alsapyer_version, METH_VARARGS, "Get current version"},

    {"play", alsapyer_play, METH_VARARGS, "Play the current song"},
    {"stop", alsapyer_stop, METH_VARARGS, "Stop the current song"},
    {"pause", alsapyer_pause, METH_VARARGS, "Pause the current song"},
    {"unpause", alsapyer_unpause, METH_VARARGS, "Continue to play the song"},
    {"next", alsapyer_next, METH_VARARGS, "Move to the next track of the playlist"},
    {"prev", alsapyer_prev, METH_VARARGS, "Move to the previous track of the playlist"},
    {"ping", alsapyer_ping, METH_VARARGS, "Check if the player is responding"},
    {"quit", alsapyer_quit, METH_VARARGS, "Close the alsaplayer session"},
    {"clear_playlist", alsapyer_clear_playlist, METH_VARARGS, "Empty the playlist"},
    {"add_path", alsapyer_add_path, METH_VARARGS, "Add a path to the playlist"},
    {"add_and_play", alsapyer_add_and_play, METH_VARARGS, "Add a path to the playlist and plays it"},
    {"add_playlist", alsapyer_add_playlist, METH_VARARGS, "Load a playlist into the current session"},
    {"shuffle_playlist", alsapyer_shuffle_playlist, METH_VARARGS, "Shuffle the playlist"},
    {"save_playlist", alsapyer_save_playlist, METH_VARARGS, "Save the current playlist"},
    {"get_playlist_length", alsapyer_get_playlist_length, METH_VARARGS, "Get the total duration of the playlist"},

    {"set_speed", alsapyer_set_speed, METH_VARARGS, "Set the speed of the current song (float value)"},
    {"get_speed", alsapyer_get_speed, METH_VARARGS, "Get the speed of the current song"},
    {"set_volume", alsapyer_set_volume, METH_VARARGS, "Set the volume of the player (0, ... ,1)"},
    {"get_volume", alsapyer_get_volume, METH_VARARGS, "Get the volume of the player"},
    {"set_pan", alsapyer_set_pan, METH_VARARGS, "Set the stereo balance of the player"},
    {"get_pan", alsapyer_get_pan, METH_VARARGS, "Get the stereo balance of the player"},

#ifdef AP_CONTROL_VERSION
    {"is_paused", alsapyer_is_paused, METH_VARARGS, "Check if the player is paused"},
#endif

    {"set_looping", alsapyer_set_looping, METH_VARARGS, "Enable Song looping"},
    {"is_looping", alsapyer_is_looping, METH_VARARGS, "Check if the song is looping"},
    {"set_playlist_looping", alsapyer_set_playlist_looping, METH_VARARGS, "Enable Playlist looping"},
    {"is_playlist_looping", alsapyer_is_playlist_looping, METH_VARARGS, "Check if playlist is looping"},

    {"get_tracks", alsapyer_get_tracks, METH_VARARGS, "Get the tracklist"},

    {"get_session_name", alsapyer_get_session_name, METH_VARARGS, "Get the name of selected session"},

    {"get_title", alsapyer_get_title, METH_VARARGS, "Get current song's title"},
    {"get_artist", alsapyer_get_artist, METH_VARARGS, "Get current song's artist"},
    {"get_album", alsapyer_get_album, METH_VARARGS, "Get current song's album"},
    {"get_genre", alsapyer_get_genre, METH_VARARGS, "Get current song's genre"},
    {"get_year", alsapyer_get_year, METH_VARARGS, "Get current song's year"},
    {"get_track_number", alsapyer_get_track_number, METH_VARARGS, "Get current song's track position in the album"},
    {"get_comment", alsapyer_get_comment, METH_VARARGS, "Get current songs'"},
    {"get_file_path", alsapyer_get_file_path, METH_VARARGS, "Get current song's path in the filesystem"},
    
    {"set_position", alsapyer_set_position, METH_VARARGS, "Set the cursor position in the track"},
    {"get_position", alsapyer_get_position, METH_VARARGS, "Get the cursor position in the track"},
    {"set_position_relative", alsapyer_set_position_relative, METH_VARARGS, "Jump in the track from the current position given an offset"},
    {"get_length", alsapyer_get_length, METH_VARARGS, "Get length"},
#ifdef AP_CONTROL_VERSION
    {"set_block", alsapyer_set_block, METH_VARARGS, " "},
    {"get_block", alsapyer_get_block, METH_VARARGS, " "},
    {"get_blocks", alsapyer_get_blocks, METH_VARARGS, " "},
#endif

    {"get_stream_type", alsapyer_get_stream_type, METH_VARARGS, "Get stream type"},
    {"get_status", alsapyer_get_status, METH_VARARGS, "Get player status"},

    {"is_playing", alsapyer_is_playing, METH_VARARGS, "Check if the player is playng"},

    {"sort", alsapyer_sort, METH_VARARGS, "Sort the playlist\n\n\
         a - sort by artist in descending direction,\n\
         A - sort by astist in ascending direction,\n\
         l - sort by album in descending direction,\n\
         L - sort by album in ascending direction,\n\
         t - sort by title in descending direction,\n\
         T - sort by title in ascending direction,\n\
         y - sort by year in descending direction,\n\
         Y - sort by year in ascending direction,\n\
         n - sort by track number in descending direction,\n\
         N - sort by track number in ascending direction,\n\
         c - sort by comment in descending direction,\n\
         C - sort by comment in ascending direction,\n\
         f - sort by filename in descending direction,\n\
         F - sort by filename in ascending direction,\n\
         g - sort by genre in descending direction,\n\
         G - sort by genre in ascending direction,\n\
         p - sort by playtime in descending direction,\n\
         P - sort by playtime in ascending direction.\n\
        "},
    {"jump_to", alsapyer_jump_to, METH_VARARGS, "Jump to a song"},

    {"get_playlist_position", alsapyer_get_playlist_position, METH_VARARGS, "Get current playlist position"},
    {"get_file_path_for_track", alsapyer_get_file_path_for_track, METH_VARARGS, "Get file path for the current track"},
    {"insert", alsapyer_insert, METH_VARARGS, "Insert in the playlist"},
    {"remove", alsapyer_remove, METH_VARARGS, "Remove from the playlist"},
    {"set_current", alsapyer_set_current, METH_VARARGS, "Set a track as the current"},

    {"get_playlist", alsapyer_get_playlist, METH_VARARGS, "Get the playlist"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "alsapyer",         /* m_name */
    NULL,               /* m_doc */
    -1,                 /* m_size */
    AlsapyerMethods,    /* m_methods */
    NULL,                /* m_reload */
    NULL,                /* m_traverse */
    NULL,                /* m_clear */
    NULL,                /* m_free */
};
#endif

PyMODINIT_FUNC
#if PY_MAJOR_VERSION >= 3
PyInit_alsapyer(void)
#else
initalsapyer(void)
#endif
{
#if PY_MAJOR_VERSION >= 3
    (void) PyModule_Create(&moduledef);
#else
    (void) Py_InitModule("alsapyer", AlsapyerMethods);
#endif
}
