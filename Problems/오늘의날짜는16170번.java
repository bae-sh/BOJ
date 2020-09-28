package 백준;
import java.util.Calendar;
public class 오늘의날짜는16170번 {

	public static void main(String[] args) {
		Calendar cal = Calendar.getInstance();
		System.out.print(cal.get(Calendar.YEAR));
		System.out.printf("-%02d-",cal.get(Calendar.MONTH)+1);
		System.out.printf("%02d",cal.get(Calendar.DAY_OF_MONTH));

	}

}
