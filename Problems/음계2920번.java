package 백준;
import java.util.*;
public class 음계2920번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a[]=new int[8];
		int b=0;// 0은 asc 1은 des 2는 mix
		for(int i=0;i<8;i++) {
			a[i]=sc.nextInt();
		}
		if(a[1]-a[0]==1) {
			for(int i=1;i<8;i++) {
				if(a[i]-a[i-1]!=1) {
					System.out.println("mixed");
					break;
				}
				if(i==7) {
					System.out.println("ascending");
				}
			}
			
		}
		else if(a[1]-a[0]==-1) {
			for(int i=1;i<8;i++) {
				if(a[i]-a[i-1]!=-1) {
					System.out.println("mixed");
					break;
				}
				if(i==7) {
					System.out.println("descending");
				}
			}
			
			
		}
		else {
			System.out.println("mixed");
		}
		
	}

}
