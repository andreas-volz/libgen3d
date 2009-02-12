#include "../include/libgen3d/util.h"

using namespace std;
using namespace Gen3D;

void Gen3D::UtilStringDelFollow (std::string &str, const std::string &characters)
{
  string::size_type pos = str.find_last_not_of(characters);
  if (string::npos != pos)
    str = str.substr(0, pos+1);
  else
  {
    // it is still possible that 'str' contains only 'characters':
    if (string::npos != str.find_first_of(characters))
      str.erase();
  }

}

void Gen3D::UtilStringDelLead (std::string &str, const std::string &characters)
{
  string::size_type pos = str.find_first_not_of(characters);
  if (string::npos != pos)
    str = str.substr(pos);
  else
  {
    // it is still possible that 'str' contains only 'characters':
    if (string::npos != str.find_first_of(characters))
      str.erase();
  }

}

void Gen3D::UtilStringDelSurround (std::string &str, const std::string &characters)
{
  string::size_type pos = str.find_first_not_of(characters);
  if (string::npos != pos)
    str = str.substr(pos);

  pos = str.find_last_not_of(characters);
  if (string::npos != pos)
    str = str.substr(0, pos+1);
  else
  {
    // it is still possible that 'str' contains only 'characters':
    if (string::npos != str.find_first_of(characters))
      str.erase();
  }
}

bool Gen3D::hasFileEnding (const std::string &filename, const std::string &ending)
{
  unsigned int loc = filename.find (ending, filename.length () - ending.length ());

  if (loc != string::npos )
  {
    return true;
  }

  return false;
}

std::string Gen3D::cutFileEnding (std::string filename, const std::string &ending)
{
  if (ending == "")
  {
    unsigned int loc = filename.find_last_of('.', filename.length ());

    if (loc != string::npos )
    {
      filename.erase (loc);
      return filename;
    }
  }
  else
  {
    unsigned int loc = filename.find (ending, filename.length () - ending.length ());

    if (loc != string::npos )
    {
      filename.erase (loc);
      return filename;
    }
  }

  return filename;
}

/*!
 * An function to replace occurences of substrings in a bigger string. Very basic function without regex.
 * @param match This is the string that is matched to replace.
 * @param replace The string that replaces all found match strings.
 * @param str The string that is matched and replaced.
 * @param maxReplace Give a int to limit the replace matches. If 0 is given there's no limit.
 */
int Gen3D::replaceString (const string& match, const string& replace, string& str, unsigned int maxReplace)
{
  int start = 0;
  unsigned int i = 0;

  if (maxReplace == 0)
    maxReplace = str.length ();

  for (; i < maxReplace; i++)
  {
    string::size_type loc = str.find (match, start);

    if (loc != string::npos)
    {
      str.replace (loc, match.length(), replace);
   }
   else
   {
     return i;
   }

    start = loc;
  }

  return i;
}

