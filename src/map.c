#include <stdlib.h>

#include "map.h"

map_t* map_new()
{
    map_t* mp = malloc(sizeof(map_t));
    
    mp->n_items = 0;
    mp->id_list = malloc(1);
    mp->data_list = malloc(sizeof(int));
    
    return mp;
}

void map_destroy(map_t* map)
{
    map->n_items = 0;
    free(map->id_list);
    free(map->data_list);
    free(map);
}

void map_put(map_t* map, const char* id, int value)
{
    
}

int map_get(map_t* map, const char* id)
{

}

char map_item_exists(map_t* map, const char* id)
{
    for (int i = 0; i < map->n_items; i++)
    {
	if ()
    }
}
