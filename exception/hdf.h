/** 
 @cond
 #########################################################################
 # GPL License                                                           #
 #                                                                       #
 # Copyright (c) 2010, Philipp Kraus, <philipp.kraus@flashpixx.de>       #
 # This program is free software: you can redistribute it and/or modify  #
 # it under the terms of the GNU General Public License as published by  #
 # the Free Software Foundation, either version 3 of the License, or     #
 # (at your option) any later version.                                   #
 #                                                                       #
 # This program is distributed in the hope that it will be useful,       #
 # but WITHOUT ANY WARRANTY; without even the implied warranty of        #
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
 # GNU General Public License for more details.                          #
 #                                                                       #
 # You should have received a copy of the GNU General Public License     #
 # along with this program.  If not, see <http://www.gnu.org/licenses/>. #
 #########################################################################
 @endcond
 **/

#ifndef MACHINELEARNING_EXCEPTION_HDF_H
#define MACHINELEARNING_EXCEPTION_HDF_H

#include <string>
#include <stdexcept>
#include <exception>

namespace machinelearning { namespace exception { namespace hdf {
    
    class sizecorrect   : public std::range_error      { public : sizecorrect( void ); };
    class simpletype    : public std::invalid_argument { public : simpletype( void ); };
    class equaltype     : public std::invalid_argument { public : equaltype( const std::string&, const std::string& ); };
    
};};};

#endif