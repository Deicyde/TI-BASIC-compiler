//
//  Variable.hpp
//  T-Script Compiler
//
//  Created by Jack McCarthy on 5/23/19.
//  Copyright © 2019 Jack McCarthy. All rights reserved.
//

#ifndef Variable_hpp
#define Variable_hpp

class Variable {
    Type const* type;
public:
    Variable(Type const* type_);
};

#endif /* Variable_hpp */
