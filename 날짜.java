package 백준;

import java.util.Scanner;

public class 날짜 {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int sum=0;
		switch(a) {
		case 12: sum+=30;
		case 11: sum+=31;
		case 10: sum+=30;
		case 9: sum+=31;
		case 8: sum+=31;
		case 7: sum+=30;
		case 6: sum+=31;
		case 5: sum+=30;
		case 4: sum+=31;
		case 3: sum+=28;
		case 2: sum+=31;
		case 1: sum+=b;
		}
		
		switch(sum%7) {
		case 0:System.out.println("SUN"); break;
		case 1:System.out.println("MON"); break;
		case 2:System.out.println("TUE"); break;
		case 3:System.out.println("WED"); break;
		case 4:System.out.println("THU"); break;
		case 5:System.out.println("FRI"); break;
		case 6:System.out.println("SAT"); break;
		
		}
	   }
	}