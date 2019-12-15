// Copyright (c) 2005-2014 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

/**
 * @file
 * @brief Generated from entity_path_table.xsd.
 */

#ifndef GDT_ENTITY_PATH_TABLE_HXX
#define GDT_ENTITY_PATH_TABLE_HXX

#ifndef XSD_CXX11
#define XSD_CXX11
#endif

#ifndef XSD_USE_WCHAR
#define XSD_USE_WCHAR
#endif

#ifndef XSD_CXX_TREE_USE_WCHAR
#define XSD_CXX_TREE_USE_WCHAR
#endif

// Begin prologue.
//
#include "shared_types.hxx"
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 4000000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include "xml_schema.hxx"

// Forward declarations.
//
namespace gdt
{
  class entity_path_t;
  class path_node_t;
  class entity_path_table;
}


#include <memory>    // ::std::unique_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search
#include <utility>   // std::move

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

#ifndef XSD_DONT_INCLUDE_INLINE
#define XSD_DONT_INCLUDE_INLINE

#include "shared_types.hxx"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "shared_types.hxx"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %
 * schema namespace.
 */
namespace gdt
{
  /**
   * @brief Class corresponding to the %entity_path_t schema type.
   *
   * @nosubgrouping
   */
  class GIDEON_CS_API entity_path_t: public ::xml_schema::type
  {
    public:
    /**
     * @name path_node
     *
     * @brief Accessor and modifier functions for the %path_node
     * sequence element.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::gdt::path_node_t path_node_type;

    /**
     * @brief Element sequence container type.
     */
    typedef ::xsd::cxx::tree::sequence< path_node_type > path_node_sequence;

    /**
     * @brief Element iterator type.
     */
    typedef path_node_sequence::iterator path_node_iterator;

    /**
     * @brief Element constant iterator type.
     */
    typedef path_node_sequence::const_iterator path_node_const_iterator;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< path_node_type, wchar_t > path_node_traits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * sequence.
     *
     * @return A constant reference to the sequence container.
     */
    const path_node_sequence&
    path_node () const;

    /**
     * @brief Return a read-write reference to the element sequence.
     *
     * @return A reference to the sequence container.
     */
    path_node_sequence&
    path_node ();

    /**
     * @brief Copy elements from a given sequence.
     *
     * @param s A sequence to copy elements from.
     *
     * For each element in @a s this function makes a copy and adds it 
     * to the sequence. Note that this operation completely changes the 
     * sequence and all old elements will be lost.
     */
    void
    path_node (const path_node_sequence& s);

    //@}

    /**
     * @name entity_path_code
     *
     * @brief Accessor and modifier functions for the %entity_path_code
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::gdt::entity_path_code_t entity_path_code_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< entity_path_code_type, wchar_t > entity_path_code_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const entity_path_code_type&
    entity_path_code () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    entity_path_code_type&
    entity_path_code ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    entity_path_code (const entity_path_code_type& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    entity_path_code (::std::unique_ptr< entity_path_code_type > p);

    //@}

    /**
     * @name is_looping
     *
     * @brief Accessor and modifier functions for the %is_looping
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::boolean is_looping_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< is_looping_type, wchar_t > is_looping_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const is_looping_type&
    is_looping () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    is_looping_type&
    is_looping ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    is_looping (const is_looping_type& x);

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Default constructor.
     *
     * Note that this constructor leaves required elements and
     * attributes uninitialized.
     */
    entity_path_t ();

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    entity_path_t (const entity_path_code_type&,
                   const is_looping_type&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    entity_path_t (const ::xercesc::DOMElement& e,
                   ::xml_schema::flags f = 0,
                   ::xml_schema::container* c = 0);

    /**
     * @brief Copy constructor.
     *
     * @param x An instance to make a copy of.
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    entity_path_t (const entity_path_t& x,
                   ::xml_schema::flags f = 0,
                   ::xml_schema::container* c = 0);

    /**
     * @brief Copy the instance polymorphically.
     *
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     * @return A pointer to the dynamically allocated copy.
     *
     * This function ensures that the dynamic type of the instance is
     * used for copying and should be used for polymorphic object
     * models instead of the copy constructor.
     */
    virtual entity_path_t*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    /**
     * @brief Copy assignment operator.
     *
     * @param x An instance to make a copy of.
     * @return A reference to itself.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    entity_path_t&
    operator= (const entity_path_t& x);

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~entity_path_t ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< wchar_t >&,
           ::xml_schema::flags);

    protected:
    path_node_sequence path_node_;
    ::xsd::cxx::tree::one< entity_path_code_type > entity_path_code_;
    ::xsd::cxx::tree::one< is_looping_type > is_looping_;

    //@endcond
  };

  /**
   * @brief Class corresponding to the %path_node_t schema type.
   *
   * @nosubgrouping
   */
  class GIDEON_CS_API path_node_t: public ::xml_schema::type
  {
    public:
    /**
     * @name x
     *
     * @brief Accessor and modifier functions for the %x
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::float_ x_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< x_type, wchar_t > x_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const x_type&
    x () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    x_type&
    x ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    x (const x_type& x);

    //@}

    /**
     * @name y
     *
     * @brief Accessor and modifier functions for the %y
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::float_ y_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< y_type, wchar_t > y_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const y_type&
    y () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    y_type&
    y ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    y (const y_type& x);

    //@}

    /**
     * @name z
     *
     * @brief Accessor and modifier functions for the %z
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::float_ z_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< z_type, wchar_t > z_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const z_type&
    z () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    z_type&
    z ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    z (const z_type& x);

    //@}

    /**
     * @name heading
     *
     * @brief Accessor and modifier functions for the %heading
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::unsigned_short heading_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< heading_type, wchar_t > heading_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const heading_type&
    heading () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    heading_type&
    heading ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    heading (const heading_type& x);

    //@}

    /**
     * @name rest_time
     *
     * @brief Accessor and modifier functions for the %rest_time
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::unsigned_int rest_time_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< rest_time_type, wchar_t > rest_time_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const rest_time_type&
    rest_time () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    rest_time_type&
    rest_time ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    rest_time (const rest_time_type& x);

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Default constructor.
     *
     * Note that this constructor leaves required elements and
     * attributes uninitialized.
     */
    path_node_t ();

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    path_node_t (const x_type&,
                 const y_type&,
                 const z_type&,
                 const heading_type&,
                 const rest_time_type&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    path_node_t (const ::xercesc::DOMElement& e,
                 ::xml_schema::flags f = 0,
                 ::xml_schema::container* c = 0);

    /**
     * @brief Copy constructor.
     *
     * @param x An instance to make a copy of.
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    path_node_t (const path_node_t& x,
                 ::xml_schema::flags f = 0,
                 ::xml_schema::container* c = 0);

    /**
     * @brief Copy the instance polymorphically.
     *
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     * @return A pointer to the dynamically allocated copy.
     *
     * This function ensures that the dynamic type of the instance is
     * used for copying and should be used for polymorphic object
     * models instead of the copy constructor.
     */
    virtual path_node_t*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    /**
     * @brief Copy assignment operator.
     *
     * @param x An instance to make a copy of.
     * @return A reference to itself.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    path_node_t&
    operator= (const path_node_t& x);

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~path_node_t ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< wchar_t >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< x_type > x_;
    ::xsd::cxx::tree::one< y_type > y_;
    ::xsd::cxx::tree::one< z_type > z_;
    ::xsd::cxx::tree::one< heading_type > heading_;
    ::xsd::cxx::tree::one< rest_time_type > rest_time_;

    //@endcond
  };

  /**
   * @brief Class corresponding to the %entity_path_table schema type.
   *
   * @nosubgrouping
   */
  class GIDEON_CS_API entity_path_table: public ::xml_schema::type
  {
    public:
    /**
     * @name entity_path_template
     *
     * @brief Accessor and modifier functions for the %entity_path_template
     * sequence element.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::gdt::entity_path_t entity_path_template_type;

    /**
     * @brief Element sequence container type.
     */
    typedef ::xsd::cxx::tree::sequence< entity_path_template_type > entity_path_template_sequence;

    /**
     * @brief Element iterator type.
     */
    typedef entity_path_template_sequence::iterator entity_path_template_iterator;

    /**
     * @brief Element constant iterator type.
     */
    typedef entity_path_template_sequence::const_iterator entity_path_template_const_iterator;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< entity_path_template_type, wchar_t > entity_path_template_traits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * sequence.
     *
     * @return A constant reference to the sequence container.
     */
    const entity_path_template_sequence&
    entity_path_template () const;

    /**
     * @brief Return a read-write reference to the element sequence.
     *
     * @return A reference to the sequence container.
     */
    entity_path_template_sequence&
    entity_path_template ();

    /**
     * @brief Copy elements from a given sequence.
     *
     * @param s A sequence to copy elements from.
     *
     * For each element in @a s this function makes a copy and adds it 
     * to the sequence. Note that this operation completely changes the 
     * sequence and all old elements will be lost.
     */
    void
    entity_path_template (const entity_path_template_sequence& s);

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    entity_path_table ();

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    entity_path_table (const ::xercesc::DOMElement& e,
                       ::xml_schema::flags f = 0,
                       ::xml_schema::container* c = 0);

    /**
     * @brief Copy constructor.
     *
     * @param x An instance to make a copy of.
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    entity_path_table (const entity_path_table& x,
                       ::xml_schema::flags f = 0,
                       ::xml_schema::container* c = 0);

    /**
     * @brief Copy the instance polymorphically.
     *
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     * @return A pointer to the dynamically allocated copy.
     *
     * This function ensures that the dynamic type of the instance is
     * used for copying and should be used for polymorphic object
     * models instead of the copy constructor.
     */
    virtual entity_path_table*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    /**
     * @brief Copy assignment operator.
     *
     * @param x An instance to make a copy of.
     * @return A reference to itself.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    entity_path_table&
    operator= (const entity_path_table& x);

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~entity_path_table ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< wchar_t >&,
           ::xml_schema::flags);

    protected:
    entity_path_template_sequence entity_path_template_;

    //@endcond
  };
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "shared_types.ixx"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace gdt
{
  /**
   * @name Parsing functions for the %entity_path_table document root.
   */
  //@{

  /**
   * @brief Parse a URI or a local file.
   *
   * @param uri A URI or a local file name.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::entity_path_table >
  entity_path_table_ (const ::std::wstring& uri,
                      ::xml_schema::flags f = 0,
                      const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a URI or a local file with an error handler.
   *
   * @param uri A URI or a local file name.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::entity_path_table >
  entity_path_table_ (const ::std::wstring& uri,
                      ::xml_schema::error_handler& eh,
                      ::xml_schema::flags f = 0,
                      const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a URI or a local file with a Xerces-C++ DOM error
   * handler.
   *
   * @param uri A URI or a local file name.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::entity_path_table >
  entity_path_table_ (const ::std::wstring& uri,
                      ::xercesc::DOMErrorHandler& eh,
                      ::xml_schema::flags f = 0,
                      const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream.
   *
   * @param is A standrad input stream.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::entity_path_table >
  entity_path_table_ (::std::istream& is,
                      ::xml_schema::flags f = 0,
                      const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with an error handler.
   *
   * @param is A standrad input stream.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::entity_path_table >
  entity_path_table_ (::std::istream& is,
                      ::xml_schema::error_handler& eh,
                      ::xml_schema::flags f = 0,
                      const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a Xerces-C++ DOM error
   * handler.
   *
   * @param is A standrad input stream.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::entity_path_table >
  entity_path_table_ (::std::istream& is,
                      ::xercesc::DOMErrorHandler& eh,
                      ::xml_schema::flags f = 0,
                      const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a resource id.
   *
   * @param is A standrad input stream.
   * @param id A resource id.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * The resource id is used to identify the document being parsed in
   * diagnostics as well as to resolve relative paths.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::entity_path_table >
  entity_path_table_ (::std::istream& is,
                      const ::std::wstring& id,
                      ::xml_schema::flags f = 0,
                      const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a resource id and an
   * error handler.
   *
   * @param is A standrad input stream.
   * @param id A resource id.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * The resource id is used to identify the document being parsed in
   * diagnostics as well as to resolve relative paths.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::entity_path_table >
  entity_path_table_ (::std::istream& is,
                      const ::std::wstring& id,
                      ::xml_schema::error_handler& eh,
                      ::xml_schema::flags f = 0,
                      const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a resource id and a
   * Xerces-C++ DOM error handler.
   *
   * @param is A standrad input stream.
   * @param id A resource id.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * The resource id is used to identify the document being parsed in
   * diagnostics as well as to resolve relative paths.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::entity_path_table >
  entity_path_table_ (::std::istream& is,
                      const ::std::wstring& id,
                      ::xercesc::DOMErrorHandler& eh,
                      ::xml_schema::flags f = 0,
                      const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ input source.
   *
   * @param is A Xerces-C++ input source.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::entity_path_table >
  entity_path_table_ (::xercesc::InputSource& is,
                      ::xml_schema::flags f = 0,
                      const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ input source with an error handler.
   *
   * @param is A Xerces-C++ input source.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::entity_path_table >
  entity_path_table_ (::xercesc::InputSource& is,
                      ::xml_schema::error_handler& eh,
                      ::xml_schema::flags f = 0,
                      const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ input source with a Xerces-C++ DOM
   * error handler.
   *
   * @param is A Xerces-C++ input source.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::entity_path_table >
  entity_path_table_ (::xercesc::InputSource& is,
                      ::xercesc::DOMErrorHandler& eh,
                      ::xml_schema::flags f = 0,
                      const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ DOM document.
   *
   * @param d A Xerces-C++ DOM document.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::entity_path_table >
  entity_path_table_ (const ::xercesc::DOMDocument& d,
                      ::xml_schema::flags f = 0,
                      const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ DOM document.
   *
   * @param d A pointer to the Xerces-C++ DOM document.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function is normally used together with the keep_dom and
   * own_dom parsing flags to assign ownership of the DOM document
   * to the object model.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::entity_path_table >
  entity_path_table_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
                      ::xml_schema::flags f = 0,
                      const ::xml_schema::properties& p = ::xml_schema::properties ());

  //@}
}

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

namespace gdt
{
  /**
   * @name Serialization functions for the %entity_path_table document root.
   */
  //@{

  /**
   * @brief Serialize to a standard output stream.
   *
   * @param os A standrad output stream.
   * @param x An object model to serialize.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function uses exceptions to report serialization errors.
   */
  GIDEON_CS_API
  void
  entity_path_table_ (::std::ostream& os,
                      const ::gdt::entity_path_table& x, 
                      const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                      const ::std::wstring& e = L"UTF-8",
                      ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a standard output stream with an error handler.
   *
   * @param os A standrad output stream.
   * @param x An object model to serialize.
   * @param eh An error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  entity_path_table_ (::std::ostream& os,
                      const ::gdt::entity_path_table& x, 
                      ::xml_schema::error_handler& eh,
                      const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                      const ::std::wstring& e = L"UTF-8",
                      ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a standard output stream with a Xerces-C++ DOM
   * error handler.
   *
   * @param os A standrad output stream.
   * @param x An object model to serialize.
   * @param eh A Xerces-C++ DOM error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  entity_path_table_ (::std::ostream& os,
                      const ::gdt::entity_path_table& x, 
                      ::xercesc::DOMErrorHandler& eh,
                      const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                      const ::std::wstring& e = L"UTF-8",
                      ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a Xerces-C++ XML format target.
   *
   * @param ft A Xerces-C++ XML format target.
   * @param x An object model to serialize.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function uses exceptions to report serialization errors.
   */
  GIDEON_CS_API
  void
  entity_path_table_ (::xercesc::XMLFormatTarget& ft,
                      const ::gdt::entity_path_table& x, 
                      const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                      const ::std::wstring& e = L"UTF-8",
                      ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a Xerces-C++ XML format target with an error
   * handler.
   *
   * @param ft A Xerces-C++ XML format target.
   * @param x An object model to serialize.
   * @param eh An error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  entity_path_table_ (::xercesc::XMLFormatTarget& ft,
                      const ::gdt::entity_path_table& x, 
                      ::xml_schema::error_handler& eh,
                      const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                      const ::std::wstring& e = L"UTF-8",
                      ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a Xerces-C++ XML format target with a
   * Xerces-C++ DOM error handler.
   *
   * @param ft A Xerces-C++ XML format target.
   * @param x An object model to serialize.
   * @param eh A Xerces-C++ DOM error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  entity_path_table_ (::xercesc::XMLFormatTarget& ft,
                      const ::gdt::entity_path_table& x, 
                      ::xercesc::DOMErrorHandler& eh,
                      const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                      const ::std::wstring& e = L"UTF-8",
                      ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to an existing Xerces-C++ DOM document.
   *
   * @param d A Xerces-C++ DOM document.
   * @param x An object model to serialize.
   * @param f Serialization flags.
   *
   * Note that it is your responsibility to create the DOM document
   * with the correct root element as well as set the necessary
   * namespace mapping attributes.
   */
  GIDEON_CS_API
  void
  entity_path_table_ (::xercesc::DOMDocument& d,
                      const ::gdt::entity_path_table& x,
                      ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a new Xerces-C++ DOM document.
   *
   * @param x An object model to serialize.
   * @param m A namespace information map.
   * @param f Serialization flags.
   * @return A pointer to the new Xerces-C++ DOM document.
   */
  GIDEON_CS_API
  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
  entity_path_table_ (const ::gdt::entity_path_table& x, 
                      const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                      ::xml_schema::flags f = 0);

  //@}

  GIDEON_CS_API
  void
  operator<< (::xercesc::DOMElement&, const entity_path_t&);

  GIDEON_CS_API
  void
  operator<< (::xercesc::DOMElement&, const path_node_t&);

  GIDEON_CS_API
  void
  operator<< (::xercesc::DOMElement&, const entity_path_table&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "entity_path_table.ixx"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_ENTITY_PATH_TABLE_HXX
