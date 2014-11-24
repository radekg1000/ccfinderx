#include "../common/ffuncrenamer.h"

#include "rawclonepairdata.h"


bool read_line(std::string *pLine, FILE *pFile)
{
    std::string line;
    boost::array<char, 1024> buf;
    while (true) {
        if (fgets(&buf[0], buf.size(), pFile) == NULL) {
            return false; // eof
        }
        boost::array<char, 1024>::iterator p = std::find(buf.begin(), buf.end(), '\n');
        if (p != buf.end()) {
            line.append(buf.begin(), p);
            (*pLine).swap(line);
            return true;
        }
        else {
            p = std::find(buf.begin(), buf.end(), '\0');
            assert(p != buf.end());
            line.append(buf.begin(), p);
        }
    }
}

bool is_ascii_nocontrol(const std::string &line)
{
    for (size_t i = 0; i < line.length(); ++i) {
        int ch = line[i];
        if (! (0x20 <= ch && ch <= 0x7f)) {
            return false;
        }
    }
    return true;
}

bool is_utf8_nocontrol(const std::string &line)
{
    size_t pos = 0;
    while (pos < line.length()) {
        size_t nextPos = nextCharUTF8String(line, pos);
        if (nextPos > pos) {
            if (nextPos - pos == 1) {
                int ch = line[pos];
                if (ch < 0x20 || ch == 0x7f) {
                    return false;
                }
            }
        }
        else {
            assert(false);
            return false;
        }
        pos = nextPos;
    }
    return true;
}

bool is_name(const std::string &str)
{
    std::string::size_type p = 0;
    if (p == str.length()) {
        return false;
    }
    char ch = str[p];
    if (! (ch == '_' || 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z')) {
        return false;
    }
    ++p;
    while (p != str.length()) {
        ch = str[p];
        if (! (ch == '_' || 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || '0' <= ch && ch <= '9')) {
            return false;
        }
        ++p;
    }
    return true;
}


namespace rawclonepair {

#if defined LITTLE_ENDIAN

size_t fwrite_RawClonePair(const RawClonePair *ary, size_t count, FILE *pOutput)
{
	return FWRITE(ary, sizeof(RawClonePair), count, pOutput);
}

size_t fread_RawClonePair(RawClonePair *ary, size_t count, FILE *pInput)
{
	return FREAD(ary, sizeof(RawClonePair), count, pInput);
}

#else

size_t fwrite_RawClonePair(const RawClonePair *ary, size_t count, FILE *pOutput)
{
	size_t successfullyWrittenCount = 0;
	for (size_t i = 0; i < count; ++i) {
		RawClonePair data = ary[i];
		flip_endian(data.left.file);
		flip_endian(data.left.begin);
		flip_endian(data.left.end);
		flip_endian(data.right.file);
		flip_endian(data.right.begin);
		flip_endian(data.right.end);
		size_t c = FWRITE(&data, sizeof(RawClonePair), 1, pOutput);
		if (c == 0) {
			break; 
		}
		++successfullyWrittenCount;
	}
	return successfullyWrittenCount;
}

size_t fread_RawClonePair(RawClonePair *ary, size_t count, FILE *pInput)
{
	size_t successfullyReadCount = 0;
	for (size_t i = 0; i < count; ++i) {
		RawClonePair &data = ary[i];
		size_t c = FREAD(&data, sizeof(RawClonePair), 1, pInput);
		if (c == 0) {
			break; 
		}
		flip_endian(data.left.file);
		flip_endian(data.left.begin);
		flip_endian(data.left.end);
		flip_endian(data.right.file);
		flip_endian(data.right.begin);
		flip_endian(data.right.end);
		++successfullyReadCount;
	}
	return successfullyReadCount;
}

#endif

}; // namespace rawclonepair
