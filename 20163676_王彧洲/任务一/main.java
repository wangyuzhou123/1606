package WuYang;
import java.util.*;
public class lianxi07 
{
public static void main(String[] args) 
  {
   int abcCount = 0;//英文字母个数
   int spaceCount = 0;//空格键个数
   int numCount = 0;//数字个数
   int otherCount = 0;//其他字符个数
   Scanner scan = new Scanner(System.in);//扫描器接受控制台的输入信息
   System.out.println("输入一组字符");
   String str = scan.nextLine();//取出控制台的一行信息,也就是你输入的信息
   char[] ch = str.toCharArray();//把取道的字符串变成一个char数组
   for (int i = 0; i<ch.length; i++)
       {
	if (Character.isLetter(ch[i])){
	//判断是否字母
	abcCount++;
		}
	else if (Character.isDigit(ch[i])){
	//判断是否数字
	numCount++;
		}
	else if (Character.isSpaceChar(ch[i])){
	//判断是否空格键
	spaceCount++;
		}
	else{
	//以上都不是则认为是其他字符
	otherCount++;
		}
	}
        System.out.println("字母个数：" + abcCount);
	System.out.println("数字个数：" + numCount);
	System.out.println("空格个数：" + spaceCount);
	System.out.println("其他字符个数：" + otherCount);
  }
}