#include"Postfix expression.h"
void   Postfix_Expression()
{
	int size = sizeof(RNPArry)/sizeof(cell);
	std::stack<int> stack1;
	for(int i=0;i<size;i++)
	{
		if(RNPArry[i]._symbol == OP_NUM )
		{
			stack1.push(RNPArry[i]._value);
		}
		else
		{
			int right = stack1.top();
			stack1.pop();
			int left = stack1.top();
			stack1.pop();
			switch(RNPArry[i]._value)
			{
			case ADD:
				stack1.push(left+right);
			    break;
			case SUB:
				stack1.push(left-right);
				break;
			case MUL:
				stack1.push(left*right);
				break;
			case DIV:
				stack1.push(left/right);
				break;
			default:
				cout<<"无此种情况"<<endl;
			}
		}
	}
	     cout<<"运算结果为："<<stack1.top()<<endl;
}

int main()
	{
		Postfix_Expression();
		system("pause");
		return 0;
	}



	
