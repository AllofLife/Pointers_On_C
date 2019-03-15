/*
 * 这个程序从标准输入输出中读取输入行，并在标准输出行中打印这些输入行
 * 每个输入行的后面一行是该行内容的一部分。（呃呃，啥意思没看懂）
 * 输入的第一行是一串序列号串的最后以一个负数结尾，
 * 这些标号成对出现，说明需要打印的输入行的列的范围
 * 例如：０，３，１０，１２，－１；　表示第０列到第三列的，第１０－１２列的内容将被打印
 * 
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define  MAX_COLS 20	//所能处理的最大列号？？不是吧，看了后发现书里面的中文注释写错了,
							//应该是“所能处理的最多列数”，最大的列号让人有一种２０列之后的就不能处理的感觉
# define MAX_INPUT 1000   //每个输入行的最大长度		

int read_columns(int columns[],int max); //读取输入行函数
void rearrange(char *input,char const *output,int n_columns,int const columns[]);//	将输入行切片		
int main( void ){//(void)是跟 int argc,char **argv 对应吗
	int n_columns;			//进行处理的列的标号的数量　n-numbers
	int columns[MAX_COLS];	//需要处理的列数，一对一对的输入，切片是有头有尾的
	char input[MAX_INPUT];	//容纳输入行的数组
	char output[MAX_INPUT];	//容纳输出行的数组
	
	/*
	 *读取该串的序列号
	 *  
	*/
	n_columns =read_columns(columns,MAX_COLS);
	
	/*
	 *读取，处理和打印 剩余的输入行
	*/
	printf("please input the string \n");
	while(fgets(input,sizeof(input),stdin) != NULL){
		printf("Original input:%s\n",input);//此处传的是指针
	    rearrange(output,input,n_columns,columns);
		printf("Rearranged line:%s\n",output);
		}
	
	return EXIT_SUCCESS;
	
	}
	
int read_columns(int columns[],int max){
	int num=0;
	int ch;
	/*
	 *获取列号，遇到输入的数字小于０则停止 
	 */
	 printf("Please input the cut numbers\n");
	 while(num<max && scanf("%d",&columns[num])==1 && columns[num]>=0){
		 num+=1;//mum的数量不包括－１
	 }
		 /*
		  * 		确认已经读取的标号为偶数个，因为他们是以对的形式出现的
		 */
		  
		  if(num%2!=0){
			  fputs("Last columns number is not paired.",stdout);//这两句之前没有遇到过但是能猜出他们的用法　打印一行，退出程序			 
			  exit(EXIT_FAILURE);
		  }
		  //现在整个数组已经有了所有的切片下标
		  //但是下面的一段程序注释为：
		  /*
		   * 丢弃该行的最后一部分数字的内容
		  */
		  while((ch = getchar())!=EOF && ch != '\n')
		  ;	  				
	return num;
}
//i guse that this progreamll use a //lot const key world ,this action semmed to protect the value of the verlibe
// progress the input ,join the speacial columns ,print the line end of the null
void rearrange(char *output,char const *input,int n_columns,int const columns[]){
	int col;	//the signal of the arrary of 'columns'
	int output_col;		//the counter of the output columns ?? i look the code where use it ,it sems that this var help the output arrary copy data from input arrary ,it help to comfim the posion of the pointer
	int len;  			//the length of the input arrary;
	
	len=strlen(input);
	output_col = 0;
	
	/*
	 * progress the  Pair of subscripts  
	*/
	
	for(col = 0; col < n_columns; col += 2 ){
		int nchars = columns[col + 1]  - columns[col] + 1;//??rember to plus one ,for example 3 - 2 =1 but it hava tow numbers
		
		
		
		/*
		 * if the  output arrary is fulled or the input arrary is end,break the for ceccyle
		*/
		if(columns[col] >= len || output_col == MAX_COLS){
			break;
			}
		
		/*
		 * if the output  arrary's size is not enough  , make the output arrary full
		 */
		 if(output_col + nchars > MAX_INPUT -1){
			 //??the reason - 1 is that the arrary count from the zero why do this juement 
			 //is that wo can kown the cuyt num whether biger than input arrary length 
			 // we input the cut num begain the input arrary
			nchars = MAX_INPUT-output_col-1;
		}
		/*
		 * copy the data of the part of the input arrary to output arrary 
		*/
		strncpy( output + output_col, input + columns[col],nchars);
		output_col += nchars;
	
	}
		output[output_col] = '\0';
	}







