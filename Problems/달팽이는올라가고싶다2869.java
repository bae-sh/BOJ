import java.util.*;
public class 달팽이는올라가고싶다2869 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		double a=sc.nextInt();
		double b=sc.nextInt();
		double v=sc.nextInt();
		
		double k=(v-a)/(a-b);
		int days=(int) Math.ceil(k);
		System.out.println(days+1);
	}

}
