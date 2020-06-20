
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_relAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_relAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, alpha_rel );

  }

  Nygren_1998i_relAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, alpha_rel );


  virtual void initialize()
  {
    Process::initialize();

    i_rel  = getVariableReference( "i_rel" ).getVariable();
    F2  = getVariableReference( "F2" ).getVariable();
    Ca_rel  = getVariableReference( "Ca_rel" ).getVariable();
    Ca_i  = getVariableReference( "Ca_i" ).getVariable();

  }

  virtual void fire()
  {
    i_rel->setValue( 1 * (alpha_rel*(pow(F2->getValue()/(F2->getValue()+0.250000), 2.00000))*((Ca_rel->getMolarConc()*1000)-(Ca_i->getMolarConc()*1000))) );

  }

 protected:

  Variable* i_rel;
  Variable* F2;
  Variable* Ca_rel;
  Variable* Ca_i;

  Real alpha_rel;

};

LIBECS_DM_INIT( Nygren_1998i_relAssignmentProcess, Process );
