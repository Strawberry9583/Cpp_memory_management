// use the micro to disable the warning;
#define _SILENCE_STDEXT_ALLOCATORS_DEPRECATION_WARNING


#include<allocators>
#include<iostream>

// reference: memory management course by Hou Junjie
// course links: https://www.bilibili.com/video/BV1ub411W7AQ
// useful links:
// https://blog.csdn.net/linuxheik/article/details/80449059
namespace primitives {

	void allocator_usage() {
		// allocate a int buffer of size==3;
		int * int_ptr = std::allocator<int>().allocate(3);
		int_ptr[0] = 0;
		int_ptr[1] = 1;
		int_ptr[2] = 2;
		std::cout << "assigned value to the memory allocated by allocator: ";
		for (int idx = 0; idx < 3; ++idx) {
			std::cout << int_ptr[idx] << " ";
		}
		// need to pass the size to deallocate
		std::allocator<int>().deallocate(int_ptr, 3);
		std::cout << std::endl;

	}
	// expression new (new operator)
	void expression_new() {
		// expression new to allocate;
		int * int_ptr = new int[3];
		int_ptr[0] = 0;
		int_ptr[1] = 1;
		int_ptr[2] = 2;
		std::cout << "assigned value to expression new memory: ";
		for (int idx = 0; idx < 3; ++idx) {
			std::cout << int_ptr[idx] << " ";
		}
		// expression delete to deallocate;
		delete[] int_ptr;
		std::cout << std::endl;

	}

	// operator new can be overload, which will be called by expression new (new operator);
	void operator_new() {
		// operator new to allocate memory;
		void * void_ptr = ::operator new(sizeof(int) * 3);
		// cast the void* to target type ptr;
		int * int_ptr = static_cast<int*>(void_ptr);
		int_ptr[0] = 0;
		int_ptr[1] = 1;
		int_ptr[2] = 2;
		std::cout << "assigned value to operator new memory: ";
		for (int idx = 0; idx < 3; ++idx) {
			std::cout << int_ptr[idx] << " ";
		}
		// operator delete to deallocate;
		::operator delete(int_ptr);
		std::cout << std::endl;
	}

	// placement new to use the allocated memory re-assign the value in previous memory;
	void placement_new() {
		int * void_ptr = new int(1);
		std::cout << "value before placement new: " << *void_ptr << std::endl;
		//int * void_ptr = temp_ptr;
		new(void_ptr) int(2);
		std::cout << "value after placement new: " << *void_ptr << std::endl;
		delete void_ptr;
		std::cout << std::endl;
	}

	void test() {
		primitives::allocator_usage();
		primitives::expression_new();
		primitives::operator_new();
		primitives::placement_new();
	}
}


int main() {
	primitives::test();
	std::cin.get();
}