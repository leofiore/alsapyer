#include <Python.h>
#include <alsaplayer/control.h>

static PyObject *
alsapyer_find_session(PyObject *self, PyObject *args)
{
    char *session_name;
    int session, result;

    if (!PyArg_ParseTuple(args, "s", &session_name))
        return NULL;

    result = ap_find_session(session_name, &session);

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

    int session, *val, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_get_position(session, val);

    return Py_BuildValue("i", *val);
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

    int session, *val, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_get_length(session, val);

    return Py_BuildValue("i", *val);
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

    int session, *paused, result;

    if (!PyArg_ParseTuple(args, "i", &session))
        return NULL;

    result = ap_is_playing(session, paused);

    return Py_BuildValue("i", *paused);
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

    int session, *pos, result;

    if (!PyArg_ParseTuple(args, "ii", &session, &pos))
        return NULL;

    result = ap_get_playlist_position(session, pos);

    return Py_BuildValue("i", pos);
}

static PyObject *
alsapyer_get_file_path_for_track(PyObject *self, PyObject *args){

    int session, pos, result;
    char path[AP_FILE_PATH_MAX];

    if (!PyArg_ParseTuple(args, "isi", &session, &path, &pos))
        return NULL;

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
        ref = PyString_FromString(*(the_list + i));
        PyList_SetItem(list, (Py_ssize_t) i, ref);
    }

    return list;
}


static PyMethodDef AlsapyerMethods[] = {
    {"find_session", alsapyer_find_session, METH_VARARGS, "find session"},
    {"session_running", alsapyer_session_running, METH_VARARGS, " "},
    {"version", alsapyer_version, METH_VARARGS, " "},

    {"play", alsapyer_play, METH_VARARGS, " "},
    {"stop", alsapyer_stop, METH_VARARGS, " "},
    {"pause", alsapyer_pause, METH_VARARGS, " "},
    {"unpause", alsapyer_unpause, METH_VARARGS, " "},
    {"next", alsapyer_next, METH_VARARGS, " "},
    {"prev", alsapyer_prev, METH_VARARGS, " "},
    {"ping", alsapyer_ping, METH_VARARGS, " "},
    {"quit", alsapyer_quit, METH_VARARGS, " "},
    {"clear_playlist", alsapyer_clear_playlist, METH_VARARGS, " "},
    {"add_path", alsapyer_add_path, METH_VARARGS, " "},
    {"add_and_play", alsapyer_add_and_play, METH_VARARGS, " "},
    {"add_playlist", alsapyer_add_playlist, METH_VARARGS, " "},
    {"shuffle_playlist", alsapyer_shuffle_playlist, METH_VARARGS, " "},
    {"save_playlist", alsapyer_save_playlist, METH_VARARGS, " "},
    {"get_playlist_length", alsapyer_get_playlist_length, METH_VARARGS, " "},

    {"set_speed", alsapyer_set_speed, METH_VARARGS, " "},
    {"get_speed", alsapyer_get_speed, METH_VARARGS, " "},
    {"set_volume", alsapyer_set_volume, METH_VARARGS, " "},
    {"get_volume", alsapyer_get_volume, METH_VARARGS, " "},
    {"set_pan", alsapyer_set_pan, METH_VARARGS, " "},
    {"get_pan", alsapyer_get_pan, METH_VARARGS, " "},

#ifdef AP_CONTROL_VERSION
    {"is_paused", alsapyer_is_paused, METH_VARARGS, " "},
#endif

    {"set_looping", alsapyer_set_looping, METH_VARARGS, " "},
    {"is_looping", alsapyer_is_looping, METH_VARARGS, " "},
    {"set_playlist_looping", alsapyer_set_playlist_looping, METH_VARARGS, " "},
    {"is_playlist_looping", alsapyer_is_playlist_looping, METH_VARARGS, " "},

    {"get_tracks", alsapyer_get_tracks, METH_VARARGS, " "},

    {"get_session_name", alsapyer_get_session_name, METH_VARARGS, " "},

    {"get_title", alsapyer_get_title, METH_VARARGS, " "},
    {"get_artist", alsapyer_get_artist, METH_VARARGS, " "},
    {"get_album", alsapyer_get_album, METH_VARARGS, " "},
    {"get_genre", alsapyer_get_genre, METH_VARARGS, " "},
    {"get_year", alsapyer_get_year, METH_VARARGS, " "},
    {"get_track_number", alsapyer_get_track_number, METH_VARARGS, " "},
    {"get_comment", alsapyer_get_comment, METH_VARARGS, " "},
    {"get_file_path", alsapyer_get_file_path, METH_VARARGS, " "},
    
    {"set_position", alsapyer_set_position, METH_VARARGS, " "},
    {"get_position", alsapyer_get_position, METH_VARARGS, " "},
    {"set_position_relative", alsapyer_set_position_relative, METH_VARARGS, " "},
    {"get_length", alsapyer_get_length, METH_VARARGS, " "},
#ifdef AP_CONTROL_VERSION
    {"set_block", alsapyer_set_block, METH_VARARGS, " "},
    {"get_block", alsapyer_get_block, METH_VARARGS, " "},
    {"get_blocks", alsapyer_get_blocks, METH_VARARGS, " "},
#endif

    {"get_stream_type", alsapyer_get_stream_type, METH_VARARGS, " "},
    {"get_status", alsapyer_get_status, METH_VARARGS, " "},

    {"is_playing", alsapyer_is_playing, METH_VARARGS, " "},

    {"sort", alsapyer_sort, METH_VARARGS, " "},
    {"jump_to", alsapyer_jump_to, METH_VARARGS, " "},

    {"get_playlist_position", alsapyer_get_playlist_position, METH_VARARGS, " "},
    {"get_file_path_for_track", alsapyer_get_file_path_for_track, METH_VARARGS, " "},
    {"insert", alsapyer_insert, METH_VARARGS, " "},
    {"remove", alsapyer_remove, METH_VARARGS, " "},
    {"set_current", alsapyer_set_current, METH_VARARGS, " "},

    {"get_playlist", alsapyer_get_playlist, METH_VARARGS, " "},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
initalsapyer(void)
{
    (void) Py_InitModule("alsapyer", AlsapyerMethods);
}
