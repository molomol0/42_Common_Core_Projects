#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char **argv)
{
	std::ifstream	file;
	std::ofstream	outfile;
	std::string		replace_file;
	std::string		tmp_string;
	size_t			pos;

	if (argc != 4 || !argv[2][0] || !argv[2][0])
		std::cout << "Wrong number of arguments" << std::endl;
	else
	{
		file.open(argv[1]);
		if (!file.is_open())
		{
			std::cout << "Can't open infile" << std::endl;
			return (-1);
		}
		replace_file = argv[1];
		replace_file += ".replace";
		outfile.open(replace_file);
		if (!outfile.is_open())
		{
			file.close();
			std::cout << "Can't open infile" << std::endl;
			return (-1);
		}
		while (getline(file, tmp_string))
		{
			while ((pos = tmp_string.std::string::find(argv[2])) != std::string::npos)
			{
				tmp_string.std::string::erase(pos, strlen(argv[2]));
				tmp_string.std::string::insert(pos, argv[3]);
			}
			outfile << tmp_string << std::endl;	
		}
		file.close();
		outfile.close();
	}
}
