
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998tau_d_LAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998tau_d_LAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998tau_d_LAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    tau_d_L  = getVariableReference( "tau_d_L" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    tau_d_L->setValue( 1 * (0.00270000*exp(-(pow((V->getValue()+35.0000)/30.0000, 2.00000)))+0.00200000) );

  }

 protected:

  Variable* tau_d_L;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998tau_d_LAssignmentProcess, Process );
