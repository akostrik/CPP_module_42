#include "File.hpp"

File::File(const char *in_file_) : in_file(in_file_){
};

int File::replace(std::string s1, std::string s2) {
	std::ifstream in(this->in_file);
	std::string   in_file_string = this->in_file;
	std::ofstream out;
	std::string   content = "";
	std::string   line;
	std::size_t   pos;

	if (!in.is_open())
	{
		std::cerr << "can't open file " << this->in_file << std::endl;
		return 1;
	}

	out.open((in_file_string + ".replace").c_str());
	if (!out.is_open())
	{
		in.close();
		std::cerr << "can't open file " << (in_file_string + ".replace").c_str() << std::endl;
		return 1;
	}

	while (getline (in, line))
		content += line + "\n";
	in.close();

 	for (int i = 0; 1; )
	{
		pos = content.find(s1, i);
		if (pos == std::string::npos)
			break ;
		content.erase(pos, s1.length()).insert(pos, s2);
		i = pos + s2.length();
	}

	out << content;
	out.close();

	return 0;
};
