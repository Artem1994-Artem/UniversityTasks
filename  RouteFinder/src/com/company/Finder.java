package com.company;

public class Finder implements RoadFinder {
    char [] [] map, savemap, leftmap;
    int RoverX = 0, RoverY = 0, TargetX = 0, TargetY = 0, step = 0, lastStep;   // Координаты марсохода
    char [][] Road;
    void left() {
        if(Road[RoverY][RoverX] == '.')Road[RoverY][RoverX] ='+';
        RoverX--;
        step++;
        System.out.print('L');
    }

     void right () {
         if(Road[RoverY][RoverX] == '.')Road[RoverY][RoverX] ='+';
         RoverX++;
         step++;
         System.out.print('R');
     }
    void up() {
        if(Road[RoverY][RoverX] == '.')Road[RoverY][RoverX] ='+';
        RoverY--;
        step++;
        System.out.print('U');
    }
    void down () {
        if(Road[RoverY][RoverX] == '.')Road[RoverY][RoverX] ='+';
        RoverY++;
        step++;
        System.out.print('D');
    }
    public char[][] findRoute(char[][] map) {
        Road = map;


        for (int i = 0; i < Road.length; i++) { //Находим начальные координаты марсохода
            for (int j = 0; j < Road[i].length; j++) {
                if (Road[i][j] == '@') {
                    RoverY = i;
                    RoverX = j;
                }
            }
        }

        for (int i = 0; i < Road.length; i++) { //Находим конечные координаты
            for (int j = 0; j < Road[i].length; j++) {
                if (Road[i][j] == 'X') {
                    TargetY = i;
                    TargetX = j;
                }
            }
        }

        while (TargetX != RoverX || TargetY != RoverY) {
            while (TargetY > RoverY) {
                if (Road[RoverY + 1][RoverX] != '#') {
                    down();
                } else if(RoverX != 0){
                    left();
                }else while (RoverX != Road[RoverY].length-1){right();}
               if(TargetY != RoverY && RoverX == Road[RoverY].length-1 && Road[RoverY + 1][RoverX] == '#') {return null;}
            }




            while (TargetY < RoverY) {
                if (Road[RoverY - 1][RoverX] != '#') {
                    up();
                }
            }


          if (TargetY == RoverY) {
              while (TargetX < RoverX) {
                  if (Road[RoverY][RoverX - 1] != '#') {
                      left();
                  }
              }

              while (TargetX > RoverX) {
                  if (Road[RoverY][RoverX + 1] != '#') {
                      right();
                  }
              }
          }
        }return Road;
    }
}
