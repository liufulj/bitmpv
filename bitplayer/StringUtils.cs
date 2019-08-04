using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace bitplayer
{
    class StringUtils
    {
        public static string SecondToHour(double time)
        {
            string str = "";
            int hour = 0;
            int minute = 0;
            int second = 0;
            second = Convert.ToInt32(time);

            if (second > 60)
            {
                minute = second / 60;
                second = second % 60;
            }
            if (minute > 60)
            {
                hour = minute / 60;
                minute = minute % 60;
            }

            if (hour > 0)
            {
                str = string.Format("{0}:{1:D2}:{2:D2}", hour, minute, second);
            }
            else
            {
                str = string.Format("{0:D2}:{1:D2}",minute,second);
            }

            return str;
        }
    }
}
