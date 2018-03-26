/**
 * \file BootstrapTH1D.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class BootstrapTH1D
 *
 * @author deltutto
 */

/** \addtogroup Base

    @{*/
#ifndef __BASE_BOOTSTRAPTH1D_H__
#define __BASE_BOOTSTRAPTH1D_H__

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <map>
#include <time.h>

#include <TH1D.h>

namespace Base {

  /**
     \class BootstrapTH1D
     User defined class BootstrapTH1D ... these comments are used to generate
     doxygen documentation!
  */
  class BootstrapTH1D{
    
  public:
    
    /// Default constructor
    BootstrapTH1D(){}

    /// Constructor
    BootstrapTH1D(std::string, std::string, int, double*);
    
    /// Default destructor
    ~BootstrapTH1D(){}

    ///
    void PrintConfig(){std::cout << "_hname is " << _hname << std::endl;
    /*std::cout << "map size is " << _hmap.size() << std::endl;*/}

    ///
    void SetWeightNames(std::vector<std::string>);

    ///
    void SetAllHistograms(std::map<std::string,TH1D*>);

    ///
    int GetNbinsX();

    ///
    int GetNUniverses();

    ///
    void ResetIterator();

    ///
    bool NextUniverse(std::string & uni_name, TH1D & uni_histo);

    ///
    std::map<std::string, std::vector<TH1D>> UnpackPMHisto();

    /// Fill the value bin with a general weight and the vector of weights
    void Fill(double, double, std::vector<double>);

    ///
    TH1D GetNominal();

  protected:

    std::string _name = "[BootstrapTH1D] ";

    std::string _hname; ///< Histogram name
    std::string _title; ///< Histogram title
    int _nbins; ///< Histogram n bins
    std::vector<double> _bins; ///< Histogram bins array

    std::map<std::string, TH1D> _hmap; ///< Histogram map ("nominal", "universe1"...)
    size_t _n_weights; ///< Number of weigths to use
    std::vector<double> _weights; ///< Weigths to use
    std::vector<std::string> _wnames; ///< Weight names

    //std::map<std::string, TH1D*>::iterator _current_iterator = _hmap.begin();
    std::map<std::string, TH1D>::iterator _current_iterator; //!

  };
}

#endif
/** @} */ // end of doxygen group 
