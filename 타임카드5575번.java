package 백준;
import java.util.*;
public class 타임카드5575번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		for(int i=0;i<3;i++) {
			int d[]=new int[6];
			for(int j=0;j<6;j++) {
				d[j]=sc.nextInt();
			}
			int ans=d[3]*3600+d[4]*60+d[5]-d[0]*3600-d[1]*60-d[2];
			int a=ans/3600;
			int b=(ans%3600)/60;
			int c=(ans%3600)%60;
			System.out.println(a+" "+b+" "+c);
		}
	}

}
