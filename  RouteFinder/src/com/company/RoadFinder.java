package com.company;

public interface RoadFinder {
    /**
     * Поиск кратчайшего маршрута между двумя точками
     * @param map карта
     * @return карта с построенным маршрутом
     */
    char[][] findRoute(char[][] map);
}
