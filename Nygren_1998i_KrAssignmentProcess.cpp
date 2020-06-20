
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_KrAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_KrAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, g_Kr );

  }

  Nygren_1998i_KrAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, g_Kr );


  virtual void initialize()
  {
    Process::initialize();

    i_Kr  = getVariableReference( "i_Kr" ).getVariable();
    p_a  = getVariableReference( "p_a" ).getVariable();
    p_i  = getVariableReference( "p_i" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();
    E_K  = getVariableReference( "E_K" ).getVariable();

  }

  virtual void fire()
  {
    i_Kr->setValue( 1 * (g_Kr*p_a->getValue()*p_i->getValue()*(V->getValue()-E_K->getValue())) );

  }

 protected:

  Variable* i_Kr;
  Variable* p_a;
  Variable* p_i;
  Variable* V;
  Variable* E_K;

  Real g_Kr;

};

LIBECS_DM_INIT( Nygren_1998i_KrAssignmentProcess, Process );
