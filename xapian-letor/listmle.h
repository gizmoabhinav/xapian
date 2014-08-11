/* listmle.h: The ListMLE file.
 *
 * Copyright (C) 2012 Rishabh Mehrotra
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301
 * USA
 */

#ifndef LISTMLE_H
#define LISTMLE_H


#include <xapian.h>
#include <xapian/intrusive_ptr.h>
#include <xapian/types.h>
#include <xapian/visibility.h>

#include "ranklist.h"
#include "ranker.h"
//#include "evalmetric.h"

#include <map>
#include <vector>
#include <string>

using namespace std;

namespace Xapian {

class XAPIAN_VISIBILITY_DEFAULT ListMLE: public Ranker {

public:
    ListMLE() {};
    virtual ~ListMLE() {};

    using Ranker::rank;
    virtual Xapian::RankList rank(const Xapian::RankList rlist);

    using Ranker::set_training_data;
    virtual void set_training_data(vector<Xapian::RankList> training_data);

    using Ranker::learn_model;
    virtual void learn_model();

    using Ranker::load_model;
    virtual void load_model(const std::string & model_file_name);

    using Ranker::save_model;
    virtual void save_model(const std::string & model_file_name);

    using Ranker::score_doc;
    virtual double score_doc(Xapian::FeatureVector fv);
    

private:
    string models;
    vector<double> parameters;
    double tolerance_rate;
    double learning_rate;


    vector<double> listmle_train(vector<RankList> & samples);

};

}
#endif /* LISTMLE_H */