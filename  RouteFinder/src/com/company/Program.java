package com.company;

public class Program {
    public static void main(String[] args) {
        System.out.println("Начало программы");
        char [][] map = {
                {'.','.', '.', '@', '.'},
                {'.','#', '#', '#', '#'},
                {'.','.','.','.','.'},
                {'#','#','#','#','.'},
                {'.','X','.','.','.'}};

   Finder F = new Finder();
   map = F.findRoute(map);
        System.out.println();
   for (int i = 0; i<map.length; i++) {
       for (int j = 0; j < map[i].length; j++) {
           System.out.print(map[i][j] + " ");
       }
       System.out.println();
   }
    }
}
