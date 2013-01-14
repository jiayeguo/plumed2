/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Copyright (c) 2012 The plumed team
   (see the PEOPLE file at the root of the distribution for a list of names)

   See http://www.plumed-code.org for more information.

   This file is part of plumed, version 2.0.

   plumed is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   plumed is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with plumed.  If not, see <http://www.gnu.org/licenses/>.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#ifndef __PLUMED_tools_BiasRepresentation_h
#define __PLUMED_tools_BiasRepresentation_h

#include "Exception.h"
#include "KernelFunctions.h"
#include "File.h"
#include "Grid.h"
#include <iostream>

using namespace std;

namespace PLMD{

//+PLUMEDOC INTERNAL biasrepresentation 
/*

*/
//+ENDPLUMEDOC

/// this class implements a general purpose class that aims to 
/// provide a Grid/list of onsian representation an  
/// transparently add/remove gaussians from a bias  

class BiasRepresentation {
  public:
	  BiasRepresentation(vector<Value*> tmpvalues, Communicator &cc  ); 
	  BiasRepresentation(vector<Value*> tmpvalues, Communicator &cc , vector<string> gmin, vector<string> gmax, vector<unsigned> nbin );
	  unsigned getNumberOfDimensions();
	  void pushGaussian( const vector <double> &sigma, const double &height);
	  vector<string> getNames();
	  const vector<Value*> & getPtrToValues();
          const string & getName(unsigned i);
	  Value* getPtrToValue(unsigned i);
  private:
    int ndim; 
    bool hasgrid;
    vector<Value*> values;
    vector<string> names;
    vector<KernelFunctions*> hills;
    Grid* BiasGrid_;
    Communicator& mycomm;
    // if this is set then you rescale the hills in read and write phase 
    // so to have free energy/bias duality
    bool welltemp_;
    double biasf_;
};

}

#endif
