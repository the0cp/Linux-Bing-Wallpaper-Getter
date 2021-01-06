/***************************************************************************
 * Author: Theodore Cooper                                                 *                                                      
 * License: GNU General Public License                                     *                                                      
 *                                                                         *                                                      
 * Bing-Backgrounds-Getter-v1.2.2                                          *
 *                                                                         *
 * Copyright (C) 2021 Theodore Cooper <ccooperr2005@gmail.com>             *
 *                                                                         *
 * This program is free software: you can redistribute it and/or modify    *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation, either version 3 of the License, or       *
 * (at your option) any later version.                                     *
 *                                                                         *
 * This program is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.   *                                                                                       *
 ***************************************************************************/

#include "../include/proc.h"
#include "../include/download.h"
#include "../include/write_data.h"
#include "../include/color.h"

int main(int argc, char *argv[])
{  
  int opt;
  int kb_yn;
  opterr = 0;

  if(argc==1)
  {
    char *time = geTime();
    char *user = getlogin();
    char *deskenv;
    conf(user);
    makeDir(time, user);
    int fileChackres = checkFile(time, user);
        
    if(fileChackres == 1)
    {
      printf(NONE"Set wallpaper as background?[y/n]");
      while(kb_yn = getchar())	//whether set as background
		  {
		  	if(kb_yn == 121)	//get 'y'
		  	{
		  		deskenv = readConf();
          excu(time, user, deskenv);
          exit(1);
		  	}
		  	else if(kb_yn == 110)	//get 'n'
		  	{
          printf(NONE"EXIT...\n");
		  		exit(1);
		  	}
		  }
    }
    deskenv = readConf();
    downloadXml(time, user);
    if(downloadImg(time, user) == 0)
    {
      excu(time, user, deskenv);
    }
    else
    {
      printf(RED"FAILED TO DOWNLOAD WALLPAPER!!!\n");
    }
  }
  else
  {
    while((opt = getopt(argc, argv, "dshv")) != -1)
    {
      if(opt == 's')
      {
        char *time = geTime();
        char *user = getlogin();
        conf(user);
        makeDir(time, user);
        int fileChackres = checkFile(time, user);

        if(fileChackres == 0)
        {
          downloadXml(time, user);
          downloadImg(time, user);
        }
        else if(fileChackres == 1)
        {
          printf(NONE"EXIT...\n");
          exit(1);
        }
        
      }
      else if(opt == 'd')
      {
        char *time = geTime();
        char *user = getlogin();
        char *deskenv;
        conf(user);
        makeDir(time, user);
        int fileChackres = checkFile(time, user);
        
        if(fileChackres == 1)
        {
          while(kb_yn = getchar())	//whether set as background
				  {
            printf(NONE"Set wallpaper as background?[y/n]");
				  	if(kb_yn == 121)	//get 'y'
				  	{
				  		deskenv = readConf();
              excu(time, user, deskenv);
              exit(1);
				  	}
				  	else if(kb_yn == 110)	//get 'n'
				  	{
              printf(NONE"EXIT...\n");
				  		exit(1);
				  	}
				  }
        }
        deskenv = readConf();
        downloadXml(time, user);
        if(downloadImg(time, user) == 0)
        {
          excu(time, user, deskenv);
        }
        else
        {
          printf(RED"FAILED TO DOWNLOAD WALLPAPER!!!\n");
        }
      }
      else if(opt == 'h')
      {
        usage();
      }
      else if (opt == 'v')
      {
        printf(YELLOW"\nBing Backgrounds Getter v1.2.2\nCopyright (C) 2021 Theodore Cooper <ccooperr2005@gmail.com>\n\n");
      }
      else
      {
        usage();
      }
    }
  }
  
  return 0;
}
