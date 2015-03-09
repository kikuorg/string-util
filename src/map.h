#ifndef MAP_H
#define MAP_H

typedef struct
{
    int n_items;
    char** id_list;
    int*  data_list;
} map_t;

map_t* map_new();
void   map_destroy(map_t* map);
void   map_put(map_t* map, const char* id, int value);
int    map_get(map_t* map, const char* id);

#endif
