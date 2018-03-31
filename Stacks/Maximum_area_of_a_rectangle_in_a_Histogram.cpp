/*
Find the Maximum rectangle area in a Histogram.
Given array of numbers , Represents the length of each bar
Ex: [5,3,2,4,2,6] - maxarea = 12
[5,4,5,6,2,2] - maxarea = 16

 Given an array representing height of bar in bar graph, find max histogram
 * area in the bar graph. Max histogram will be max rectangular area in the
 * graph.
 *
 * Maintain a stack
 *
 * If stack is empty or value at index of stack is less than or equal to value at current
 * index, push this into stack.
 * Otherwise keep removing values from stack till value at index at top of stack is
 * less than value at current index.
 * While removing value from stack calculate area
 * if stack is empty
 * it means that till this point value just removed has to be smallest element
 * so area = input[top] * i
 * if stack is not empty then this value at index top is less than or equal to
 * everything from stack top + 1 till i. So area will
 * area = input[top] * (i - stack.peek() - 1);
 * Finally maxArea is area if area is greater than maxArea.
 *
 *
 * Time complexity is O(n)
 * Space complexity is O(n)
*/


#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{

    int area=0,max_area=0,i=0;
    vector<int> input={5,3,2,4,2,6};
    stack<int> st;

    for(i=0;i<input.size();)
    {
        //check current value is greater than the val@stack top, if Yes, push index
        if(st.empty()||input[st.top()]<=input[i]){
            st.push(i++);
        }
        else //Pop the value from stack, while poping calculate the area
        {
           int top=st.top(); // before pop , store top value.
            st.pop();  //Pop the value
            if(st.empty()){ //check if stack empty
                area = input[top]*i;
            }
            else{
                area = input[top]*(i-st.top()-1);
            }
            //Update the max area
            if(area>max_area)
                max_area=area;
        }
    }
    //After reach at the end, Pop all the elements from stack.
    //while poping calculate the area same as above.
    while(!st.empty())
    {
           int top=st.top();
            st.pop();
            if(st.empty()){
                area = input[top]*i;
            }
            else{
                area = input[top]*(i-st.top()-1);
            }

            if(area>max_area)
                max_area=area;

    }

    cout<<"max_area : "<<max_area<<endl;

}
