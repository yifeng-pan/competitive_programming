/*
https://open.kattis.com/problems/autori
*/

import java.util.Scanner;

public class Autori {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String os = "";
        os = os.concat(s.substring(0,1));
        for(int i = 0; i < s.length() - 1; i++){
            if(s.substring(i,i+1).equals("-")){
                os = os.concat(s.substring(i+1,i+2));
            }
        }
        System.out.println(os);
        sc.close();
    }
}
