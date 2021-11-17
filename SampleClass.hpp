#pragma once

class SampleClass{
	public:
		SampleClass(){
			_nums = new int[4];
		}
		SampleClass(SampleClass const & src){
			_nums = new int[4];
			for (int i = 0; i < 4; i++){
				_nums[i] = src._nums[i];
			}
		}
		SampleClass & operator=(SampleClass const & src){
			delete [] _nums;
			_nums = new int[4];
			for (int i = 0; i < 4; i++){
				_nums[i] = src._nums[i];
			}
			return (*this);
		}
		~SampleClass(){
			delete [] _nums;
		}

	private:
		int *_nums;
};
