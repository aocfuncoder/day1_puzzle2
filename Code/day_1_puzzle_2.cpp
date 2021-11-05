#include <iostream>
#include <fstream>

class floor_finder{
private:
    int32_t count_parentheses_ = 0;
    int32_t negative_position_ = 0;
    std::ifstream input_file_;

public:
    void display_file_count(int argc);
    void open_file(const char * file_name);
	void close_file();
    bool display_open_file_status();
    bool get_file_status();
    char get_floor();
    void set_count_parentheses(char floor_parentheses);
    void set_negative_position();
    int get_count_parentheses();
    int get_negative_position();
    void display_floor_position();

};

void floor_finder::display_file_count(int argc)
{
    int32_t input_file_count = 0;
    input_file_count = argc - 1;

    if(input_file_count<=1)
    {
        std::cout<< "There is " << input_file_count << " file." << std::endl;
    }
    else
    {
        std::cout<< "There are " << input_file_count << " files." << std::endl;
    }
};

void floor_finder::open_file(const char * file_name)
{
    input_file_.open(file_name);
};

bool floor_finder::display_open_file_status()
{
    if ( input_file_.is_open())
    {
        std::cout<< "Open file success" << std::endl;
        return true;
    }
    else
    {
        std::cout<< "Open file error" << std::endl;
    }
    return false;

};

bool floor_finder::get_file_status()
{
    if(input_file_)
    {
        return true;
    }

	return false;

}

void floor_finder::close_file()
{
	input_file_.close();
}

char floor_finder::get_floor()
{
    return input_file_.get();
};

void floor_finder::set_count_parentheses(char floor_parentheses)
{
    if(floor_parentheses=='(')
    {
        count_parentheses_++;
    }
    else if(floor_parentheses==')')
    {
        count_parentheses_--;
    }
}

void floor_finder::set_negative_position()
{
    negative_position_++;
}

int floor_finder::get_count_parentheses()
{
    return count_parentheses_;
}

int floor_finder::get_negative_position()
{
    return negative_position_;
}

void floor_finder::display_floor_position()
{
    if(count_parentheses_==-1)
    {
        std::cout<< "The position of the character that causes Santa to first enter the basement: " << negative_position_ << std::endl;
    }
    else
    {
        std::cout<< "The Santa does not need to enter the basement. " << std::endl;
    }
}

int main(int argc, const char * argv[]) {

    floor_finder floor;

    floor.display_file_count(argc);

    for (int i = 1; i < argc; i++)
    {
        floor.open_file(argv[i]);
        floor.display_open_file_status();
        while(floor.get_file_status())
        {
            floor.set_count_parentheses(floor.get_floor());
            floor.set_negative_position();
            if(floor.get_count_parentheses()==-1)
            {
                break;
            }
        }
        floor.display_floor_position();
		floor.close_file();
    }

    return 0;
}
