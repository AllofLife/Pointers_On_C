/*这是一个验证性的测试，测试内容是函数调用的本质，函数的参数的地址，函数返回值的地址。
 * 在阅读《码农翻身》的时候，在第一章节的最后一小节，书中标题是：递归那些事
 * 递归在程序中的用处实在是太多了，然而好的递归和差的递归性能的差别很大。
 * 在文章中提出了传统的递归，每递归一次，就要开辟一个函数栈的内存，用来存放函数的参数，返回值，等等
 * 文章最后介绍了一种新的递归我们称呼它为改进后的递归，和传统递归最大的不同就是改进后的递归输入参数增加了一个，
 * 返回值减少了一个运算，把本来在返回值进行的运算，放在了函数的参数里面计算。
 * 文中称这种改进后的递归为尾递归，尾递归最大的特点就是复用栈帧。也就是说空间复杂度从O(n)降低到了O(1)时间复杂度也应该有所下降
 * TODO：
 * 我将写两个函数，来计算n！，一个用传统递归，一个用尾递归（改进后的递归）
 * 分别打印出相关的信息，函数的返回值地址，参数地址等，比较二者，验证上面的分析，解答心中的疑问
 * 
 * 下面是wiki给出的解释
 * 若函数在尾位置调用自身（或是一个尾调用本身的其他函数等等），
 * 则称这种情况为尾递归。尾递归也是递归的一种特殊情形。尾递归是一种特殊的尾调用，
 * 即在尾部直接调用自身的递归函数。对尾递归的优化也是关注尾调用的主要原因。尾调用不一定是递归调用，
 * 但是尾递归特别有用，也比较容易实现
 * 特点
   尾递归在普通尾调用的基础上，多出了2个特征：
   在尾部调用的是函数自身 (Self-called)；
   可通过优化，使得计算仅占用常量栈空间 (Stack Space)。
 */
 #include<stdio.h>
 int factorial(int n);
 int new_factorial(int n,int result);
 int main(){
	  printf("orignial recursion\n");
	  printf("%d\n",factorial(4));
	  printf("new recursion\n");
	  printf("%d\n",new_factorial(4,1));	  	
	  }
int factorial(int n){
	if(n==1){
		return 1;
	}else{
	printf("%p\n",&n);
	 printf("%p\n",factorial);
	 return n * factorial(n-1) ;
	}
}	  
int new_factorial(int n,int result){
	if(n==1){
		return result;
	}else{
	 int var;
	 printf("%p\n",&var);
	 printf("%p\n",new_factorial);
	 return  new_factorial(n-1,n*result);
	}
}	
//第一个函数是像这样调用函数的	  
//call factorial (3)
   //call iter (3 1)
    //call iter (2 3)
     //call iter (1 6)
      //call iter (0 6)
      //return 6
     //return 6
    //return 6
   //return 6
  //return 6
 //第二个函数是像下面这样的
 //call factorial (3)
   //call iter (3 1)
   //将参数变为 (2 3)，跳至 "iter"
   //将参数变为 (1 6)，跳至 "iter"
   //将参数变为 (0 6)，跳至 "iter"
   //return 6
  //return 6
  //二者对比，第二种 调用方式将函数调用从非线性变成了线性的，节省了空间，空间复杂度是第一种的一半，不过这也只是常数
  //级别的两倍关系
  //在阮一峰的博客中写到这样的调用是O(n)和O（1）的差别，他的分析也有道理。博客地址：http://www.ruanyifeng.com/blog/2015/04/tail-call.html
