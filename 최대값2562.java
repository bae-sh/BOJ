import java.util.*;
public class 최대값2562 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int num=1;
		int Max=0;
		for(int i=1;i<=9;i++) {
			int input=sc.nextInt();
			if(Max<input) {
				Max=input;
				num=i;
			}
		}
		System.out.println(Max+"\n"+num);
	}

}
