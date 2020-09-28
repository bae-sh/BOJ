import java.util.*;
public class 직각삼각형4153 {

	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(true) {
			int a[]=new int[3];
			for(int i=0;i<3;i++) {
				int x=sc.nextInt();
				a[i]=x*x;
			}
			if(a[0]+a[1]+a[2]==0) {
				break;
			}
			Arrays.sort(a);
			if(a[0]+a[1]==a[2]) {
				System.out.println("right");
			}else {
				System.out.println("wrong");
			}
		}
	}

}
