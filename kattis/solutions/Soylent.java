/*
https://open.kattis.com/problems/soylent
*/

import java.util.Scanner;

public class Soylent {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int cal, bot;
        while(size != 0){
            cal = sc.nextInt();
            bot = cal / 400;
            if(cal % 400 != 0){
                bot++;
            }
            System.out.println(bot);
            size--;
        }
        sc.close();
    }
}
